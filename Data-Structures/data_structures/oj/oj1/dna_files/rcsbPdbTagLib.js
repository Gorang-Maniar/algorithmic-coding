/**
 * rcsbPdbTagLib
 * ----------------------------------------
 * Version: 2.0
 * Author: Bojan Beran
 * 
 * Description: The RCSB PDB Tag Library is created for easy embedding of PDB functionality on external websites.
 * 
 * Changes in v2: w3 compliant, params all passed through the 'title' attribute, new onload event handler, external style.
 * 
 */

/*global document:false, self: false, setTimeout: false, clearTimeout: false, escape: false, event: false, navigator: false, window: false*/

function rcsbPdbGetScreenSize() {
	var sw = 0, sh = 0; 
	if (typeof window.innerWidth != 'undefined') {
		// the more standards compliant browsers (mozilla/netscape/opera/IE7) use window.innerWidth and window.innerHeight
		sw = window.innerWidth;
		sh = window.innerHeight;
	} else if (typeof document.documentElement != 'undefined' && typeof document.documentElement.clientWidth != 'undefined' && document.documentElement.clientWidth !== 0) {
		// IE6 in standards compliant mode (i.e. with a valid doctype as the first line in the document)
		sw = document.documentElement.clientWidth;
		sh = document.documentElement.clientHeight;
	} else {
		// older versions of IE
		sw = document.getElementsByTagName('body')[0].clientWidth;
		sh = document.getElementsByTagName('body')[0].clientHeight;
	}
	return [ sw, sh ];
}

function rcsbPdbGetScreenPosition() {
	var px=0,py=0;
	if (self.pageYOffset) {
		// all except Explorer
		px = self.pageXOffset;
		py = self.pageYOffset;
	} else if (document.documentElement && document.documentElement.scrollTop) {
		// Explorer 6 Strict
		px = document.documentElement.scrollLeft;
		py = document.documentElement.scrollTop;
	} else if (document.body) {
		// all other Explorers
		px = document.body.scrollLeft;
		py = document.body.scrollTop;
	}
	return [ px, py ];
}

var rcsbPdbTooltip=function(){
	var id = 'rcsb_tooltip'; 
	var left = 10; 
	var tt,c, to; 
	var ie = document.all ? true : false;
	return{
		show:function(v, extraStyle){
			if(tt === null || typeof tt == 'undefined'){
				tt = document.createElement('div');
				tt.setAttribute('id',id);
				tt.className="rcsb_hidden";
				c = document.createElement('div');
				c.setAttribute('id',id + '_content');
				tt.appendChild(c);
				document.body.appendChild(tt);
				document.onmousemove = this.pos;
			}
			c.className = "rcsb_tooltip " + extraStyle;
			c.innerHTML = v;
			if (ie) {
				tt.className="rcsb_tooltip_wrapper";
			} else {
				to = setTimeout(function() {tt.className="rcsb_tooltip_wrapper";}, 500);
			}
			
		},
		pos:function(e){
			var u = 0;
			var l = 0;
			var screen = rcsbPdbGetScreenSize();
			var offset = rcsbPdbGetScreenPosition();
			u = ie ? event.clientY + offset[1] : e.pageY;
			l = ie ? event.clientX + offset[0] : e.pageX;
			var isIE6 = navigator.userAgent.toLowerCase().indexOf('msie 6') != -1;
			if ( (u - offset[1]) >= (screen[1]/3) * 2 ) {
				if (isIE6) {
					tt.style.top = '';
					tt.style.bottom = ( ( screen[1] + offset[1] ) - u ) - 10 + 'px';
				} else {
					tt.style.top = '';
					tt.style.bottom = (screen[1] - u) - 10 + 'px';
				}
			} else {
				tt.style.top = u + 'px';
				tt.style.bottom = '';
			}
			if ( (l - offset[0]) > screen[0]/2 ) {
				tt.style.left = '';
				tt.style.right = ((screen[0] - l) + 3) + 'px';
			} else {
				tt.style.right = '';
				tt.style.left = (l + left) + 'px';
			}
		},
		hide:function(){
			if (!ie) {
				clearTimeout(to);
			}
			tt.className="rcsb_hidden";
		}
	};
}();

var rcsbPdbTagLib = function(){
		
	// RCSB PDB Server Paths
	var server = "http://www.rcsb.org";
	var imagePath = "/pdb/images/";	
	var filePath = "/pdb/files/";
	var cssPath = "/pdb/widgets/rcsbPdbWidgets.css";
	var exploreActionPath = "/pdb/explore/explore.do?structureId=";
	var jmolActionPath = "/pdb/explore/jmol.do?structureId=";
	var keywordSearchPath = "/pdb/search/navbarsearch.do?newSearch=yes&isAuthorSearch=no&radioset=All&sgProjectSelect=&image=Search&inputQuickSearch=";
	var authorSearchPath = "/pdb/search/navbarsearch.do?newSearch=yes&exactMatch=y&isAuthorSearch=yes&radioset=Authors&sgProjectSelect=&image=Search&inputQuickSearch=";
	var sequenceActionPath = "/pdb/explore/remediatedSequence.do?structureId=";
	var seqSimActionPath = "/pdb/explore/sequenceCluster.do?structureId=";
	var structSimActionPath = "/pdb/explore/structureCluster.do?structureId=";
	var litActionPath = "/pdb/explore/literature.do?structureId=";
	
	// Regular Expression Definitions
	var classPattern = new RegExp('(^|\\\\s+)rcsb_tag(\\\\s+|$)');
	var typePattern = new RegExp('^(id|author|keyword|menu)$');
	var legacyPattern = new RegExp('(^|\\\\s+)rcsb_(id|author|keyword|menu)_tag(\\\\s+|$)');
	var isIe = /*@cc_on!@*/false;
	
	return {
		isLocalCSS: false,
		// rcsbPdbTagLib.initLib() - function is called first to iterate through the web page and insert all required functionality.
		initLib: function() { 
			
			// Check if we already have our stylesheet embedded
			var hasStyle = false;
			for (var i = 0; i < document.styleSheets.length; i++) {
				if (document.styleSheets[i].href == this.server + this.cssPath) { hasStyle = true; }
			}
			// link to our external stylesheet
			if (!rcsbPdbTagLib.isLocalCSS && !hasStyle) {
				var extCSS=document.createElement("link");
				extCSS.setAttribute("rel", "stylesheet");
				extCSS.setAttribute("type", "text/css");
				extCSS.setAttribute("href", server + cssPath);
				extCSS.setAttribute("media", "screen");
				document.getElementsByTagName("head")[0].appendChild(extCSS);
			}
			
			// get a list of all tags and iterate through them.
			var tagList=document.getElementsByTagName("*");
			if ( tagList.length > 0) {
				for (i = 0; i < tagList.length; i++) {
					// if a tag has a class label 'rcsb_tag' use the new action
					if ( classPattern.test(tagList[i].className) ) {
						rcsbPdbTagLib.processHit(tagList[i], i);
					}
					// it a tag has a class label of 'rcsb_TYPE_tag' use the legacy action
					if ( legacyPattern.test(tagList[i].className) ) {
						rcsbPdbTagLib.processLegacy(tagList[i]);
					}
				}
			}
		}, 
		
		// rcsbPdbTagLib.processHit(obj) - takes in the dom element writes the image 
		processHit: function(obj, i) {
			// use the title attribute to scrape all necessary parameters - format is 'type|param1|param2...'
			var titleString = obj.getAttribute('title');
			var params = titleString.split('|');
			if (typePattern.test(params[0])) {
				obj.className = obj.className + ' rcsb_clickable rcsb_highlighted';
				switch(params[0])
				{
					case "id":
						//title="id|1ott|This rules!"
						if (params.length == 3) {
							rcsbPdbTagLib.processId(obj, params[1], params[2]);
						}
						break;
					case "author":
						//title="author|Berman, H.">
						if (params.length == 2) {
							rcsbPdbTagLib.processAuthor(obj, params[1]);
						}
						break;
					case "keyword":
						//title="keyword|actin"
						if (params.length == 2) {
							rcsbPdbTagLib.processKeyword(obj, params[1]);
						}
						break;
					case "menu":
						//title="menu|4hhb"
						if (params.length == 2) {
							rcsbPdbTagLib.processMenu(obj, params[1]);
						}
						break;
					default:
						break;
				}
				obj.title="";
			}
		},
		
		// rcsbPdbTagLib.processLegacy(obj) - takes in the dom element writes the image 
		processLegacy: function(obj, i) {
			// use the title attribute to scrape all necessary parameters - format is 'type|param1|param2...'
			var classMatch = legacyPattern.exec(obj.className);
			if (classMatch !== null){
				obj.className = obj.className + ' rcsb_clickable rcsb_highlighted';
				switch(classMatch[0])
				{
					case "rcsb_id_tag":
						//<span class="rcsb_id_tag" title="Tobacco Mosaic Virus">2om3</span>
						var id = obj.getAttribute('rel');
						if (id === null) {
							id = obj.innerHTML.replace(/^\s+|\s+$/g,"");
						} else {
							obj.removeAttribute('rel');
						}
						var title = obj.getAttribute('title');
						if ( title === null ) {
							title ="";
						}
						rcsbPdbTagLib.processId(obj, id, title);
						break;
					case "rcsb_author_tag":
						//<span class="rcsb_author_tag" rel="Stanley, W.A.">
						var auth = obj.getAttribute('rel');
						if (auth === null) {
							auth = obj.innerHTML.replace(/\s+/,"+");
						}
						rcsbPdbTagLib.processAuthor(obj, auth);
						break;
					case "rcsb_keyword_tag":
						//<span class="rcsb_keyword_tag">RNA</span>
						var kwd = obj.getAttribute('rel');
						if (kwd === null) {
							kwd = obj.innerHTML.replace(/^\s+|\s+$/g,"");
						} else {
							obj.removeAttribute('rel');
						}
						rcsbPdbTagLib.processKeyword(obj, kwd);
						break;
					case "rcsb_menu_tag":
						//<span class="rcsb_menu_tag">2tmv</span>
						var menuId = obj.getAttribute('rel');
						if (menuId === null) {
							menuId = obj.innerHTML.replace(/^\s+|\s+$/g,"");
						} else {
							obj.removeAttribute('rel');
						}
						rcsbPdbTagLib.processMenu(obj, menuId);
						break;
					default:
						break;
				}
				obj.setAttribute('title', '');
			}
		},
		
		processId: function(obj, id, title) {
			obj.className = obj.className + ' rcsb_ext_text';
			obj.onclick = function(){
				window.open(server + exploreActionPath + id);
			};
			obj.onmouseover = function() {
				rcsbPdbTooltip.show("<img src='" + server + imagePath + id + "_bio_r_250.jpg' /><h2 class='rcsb_h2'>"+id+"</h2>"+title, "rcsb_altBg");
			};
			obj.onmouseout = function() {
				rcsbPdbTooltip.hide();
			};
		},
		
		processAuthor: function(obj, name) {
			obj.className = obj.className + ' rcsb_search_text';
			obj.onclick = function(){
				window.open(server + authorSearchPath + escape(name));
			};
			obj.onmouseover = function(e) {
				rcsbPdbTooltip.show("RCSB PDB Exact Author Search for: " + name,"");
			};
			obj.onmouseout = function() {
				rcsbPdbTooltip.hide();
			};
		},
		
		processKeyword: function(obj, keyword) {
			obj.className = obj.className + ' rcsb_search_text';
			obj.onclick = function(){
				window.open(server + keywordSearchPath + escape(keyword));
			};
			obj.onmouseover = function(e) {
				rcsbPdbTooltip.show("RCSB PDB Keyword Search for: " + keyword,"");
			};
			obj.onmouseout = function() {
				rcsbPdbTooltip.hide();
			};
		},
		
		processMenu: function(obj, id, i) {
			var to;
			obj.className = obj.className + ' rcsb_menu_text';
			obj.appendChild(rcsbPdbTagLib.createMenu(id, i));
			obj.onmouseover = function() {
				if (!isIe) {
					clearTimeout(to);
				}
				var float = 'left';
				var screen = rcsbPdbGetScreenSize();
				var ePos = this.offsetLeft;
				var vPos = this.offsetTop;
				if ( ePos > (screen[0] - 180)) {
					float = 'right';
				}
				if (float == 'left') {
					this.getElementsByTagName("span")[0].className = "rcsb_menu rcsb_menu_left";
				} else {
					this.getElementsByTagName("span")[0].className = "rcsb_menu rcsb_menu_right";
				}
				if (vPos > (screen[1] - 200)) {
					this.getElementsByTagName("span")[0].className = this.getElementsByTagName("span")[0].className + " rcsb_menu_bottom";
				} else {
					this.getElementsByTagName("span")[0].className = this.getElementsByTagName("span")[0].className + " rcsb_menu_top";
				}
			};
			obj.onmouseout = function() {
				var obj = this;
				if (isIe) {
					obj.getElementsByTagName("span")[0].className = "rcsb_hidden";
				} else {
					to = setTimeout(function(){obj.getElementsByTagName("span")[0].className = "rcsb_hidden";}, 500);
				}
			};
		},
		
		createMenu:function(id, cnt) {
			var p = document.createElement('span');
			p.setAttribute('id',id+'_div');
			p.className = "rcsb_hidden";
			
			var v = document.createElement('a');
			v.href = server + jmolActionPath + id;
			v.target = '_blank';
			v.innerHTML = 'View in 3D (JMol)';
			
			var exp = document.createElement('a');
			exp.href = server + exploreActionPath + id;
			exp.target = '_blank';
			exp.innerHTML = 'View Summary Page';
			
			var seq = document.createElement('a');
			seq.href = server + sequenceActionPath + id;
			seq.target = '_blank';
			seq.innerHTML = 'View Sequence Information';
			
			var seqsim = document.createElement('a');
			seqsim.href = server + seqSimActionPath + id;
			seqsim.target = '_blank';
			seqsim.innerHTML = 'View Sequence Similarity';
			
			var structSim = document.createElement('a');
			structSim.href = server + structSimActionPath + id;
			structSim.target = '_blank';
			structSim.innerHTML = 'View Structure Similarity';
			
			var lit = document.createElement('a');
			lit.href = server + litActionPath + id;
			lit.target = '_blank';
			lit.innerHTML = 'View Related Literature';
	
			var disp = document.createElement('a');
			disp.href = server + filePath + id + ".pdb";
			disp.target = '_blank';
			disp.innerHTML = 'Display PDB File';
	
			var dl = document.createElement('a');
			dl.href = server + filePath + id + ".pdb.gz";
			dl.innerHTML = 'Download PDB File (gz)';
	
			var brk1 = document.createElement('br');
			var brk2 = document.createElement('br');
			var brk3 = document.createElement('br');
			var brk4 = document.createElement('br');
			var brk5 = document.createElement('br');
			var brk6 = document.createElement('br');
			var hrTag = document.createElement('hr');
			p.appendChild(v);
			p.appendChild(brk1);
			p.appendChild(exp);
			p.appendChild(brk2);
			p.appendChild(seq);
			p.appendChild(brk3);
			p.appendChild(seqsim);
			p.appendChild(brk4);
			p.appendChild(structSim);
			p.appendChild(brk5);
			p.appendChild(lit);
			p.appendChild(hrTag);
			p.appendChild(disp);
			p.appendChild(brk6);
			p.appendChild(dl);
			return p;
		},
		
		// rcsbPdbTagLib.addOnloadEvent(func) - function that attaches the library actions to the onload event without interrupting user defined events.
		addOnloadEvent: function(func){
			if ( window.addEventListener ) {
				window.addEventListener( "load", func, false );
			} else if ( window.attachEvent ) {
				window.attachEvent( "onload", func );
		    } else {
				var oldOnload = window.onload || function() {};
				window.onload = function(e) {
					oldOnload(e);
					window[func](e);
				};
			}
		}
	};
}();

rcsbPdbTagLib.addOnloadEvent(function() { rcsbPdbTagLib.initLib(); });