/*-------------- Object AjaxCom --------------------------------------------------------- *
*                                                                                         *
* Object used to modify the content of one or more element, for a given action and data.  *
* The element being modified should be encapsulated in a basic element like <div>.        *
* The reason is that for some couples (browser,element), the element's parent will have   *
* to be used in order the modify the element.                                             *
* This object uses Asynchronous Javascript And Xml and is related to a servlet dispatcher *
* on the server side of the application.                                                  *
*                                                                                         *
* The public method is execAction(action,target[],data)                                   *
* ---------------------------------------------------------------------------------------*/

function ajaxCom() {

	/* Properties */
	var req;
	var target;

	/* Public methods*/
	this.execAction = ajaxCom_execAction;
	
	/* Private methods*/
	this._init = ajaxCom_init;
	this._callBack = ajaxCom_callBack;
	//this.parseMessage = ajaxCom_parseMessage;
	//this.setMessage = ajaxCom_setMessage;
	
}

function ajaxCom_execAction(action,_target,data){
	//alert("ajaxCom_execAction");
	this.action = action;
	target = _target;
	this.data = data;
	
	//alert("target: "+target);
	//alert("data: "+data);
	this._init();
}

/* Methods*/
function ajaxCom_init(){
	//alert("ajaxCom_init");
	url = "updateAjaxVal?data=" + escape(this.action) +"|"+escape(this.data); //"ajaxDispatcher";
	if (window.XMLHttpRequest) {
		req = new XMLHttpRequest();
	} else if (window.ActiveXObject) {
		req = new ActiveXObject("Microsoft.XMLHTTP");
	} else {
	//	alert("XMLHttpRequest Not Supported")
	}
	
	//alert("try to open");

	req.onreadystatechange = this._callBack;
	//req.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	req.open("GET",url,true);
	req.send("");
	
}

function ajaxCom_callBack(){
	if(req.readyState == 4)
        {  //load complete
		//alert("got something");
		if(req.status == 200)
                {  //success
		   ajaxCom_parseMessage();
		} 
                else
                {
		 alert("status: "+req.status);
		 alert("status text: "+req.statusText);
		}
	}
}

function ajaxCom_parseMessage(){
	//alert("message: "+req.responseText);
	message = req.responseXML.getElementsByTagName("message")[0];
	ajaxCom_setMessage(message.childNodes[0].childNodes[0].nodeValue, message.childNodes[1]);
}

function ajaxCom_setMessage(message,content){
	//alert("Hummm good: "+content.childNodes[0].nodeValue);
	//alert("target: "+target);
	for (var i=0;i<target.length;i++) {
                     //alert("element: "+target[i]);


		if (message == "response"){
			ajaxCom_changeContent(document.getElementById(target[i]),content.childNodes[0].nodeValue);
			document.getElementById(target[i]).style.display='block';
		} else {
			el.parentElement.innerHTML = "Nothing Selected";
		}
	}
}

function ajaxCom_changeContent(element , data){
	//alert("element: "+element);
	browser = navigator.appName;
	if (browser == "Microsoft Internet Explorer"){
          //alert("element tagName: "+element.tagName);
		if (element.tagName == "SELECT"){             /*innerHTML read-only so we use the parent*/
			t = element.outerHTML.split(/[>][<]/);
			fin = t[0]+">"+data+"<"+t[1];
			element.parentElement.innerHTML= fin;
		}
		else if (element.tagName == "TABLE"){         /*innerHTML read-only so we use the parent*/
			t = element.firstChild.outerHTML.split(/[>][<]/);
			fin = t[0]+">"+data+"<"+t[1];
			t1 = element.outerHTML.split(/<TBODY><.TBODY>/);
			fin = t1[0]+fin+t1[1];
			element.parentElement.innerHTML= fin;
		}
		else {
			element.innerHTML = data;
		}
	}
	else { /**/
		element.innerHTML = data;
	}
}