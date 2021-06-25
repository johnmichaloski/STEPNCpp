// My JScrip Lib

  function updater(input)
  {
    var ajcall = new ajaxCom();
    ajcall.execAction("updater",new Array("resId"),input);
  }
  
  function updateIndex( liveGrid, offset ) 
  {
    $('bookmark').innerHTML = "Listing Errors " + (offset+1) + " - " + 
    (offset+liveGrid.metaData.getPageSize()) +" of "+ liveGrid.metaData.getTotalRows();
  }

  function processPage(sub)
  {
      var str = "1-"+sub.value;
      updater(str);
  }
  

//ToolTip Dhtml

  var tooltip = false;
  var tooltipShadow = false;
  var shadowSize = 4;
  var tooltipMaxWidth = 200;
  var tooltipMinWidth = 100;
  var iframe = false;
  var tooltip_is_msie = (navigator.userAgent.indexOf('MSIE')>=0 && navigator.userAgent.indexOf('opera')==-1 && document.all)?true:false;
  
  function showTooltip(e,tooltipTxt)
  {
   var bodyWidth = Math.max(document.body.clientWidth,document.documentElement.clientWidth) - 20;
   if(!tooltip)
   {
    tooltip = document.createElement('div');
    tooltip.id = 'tooltip';
    tooltipShadow = document.createElement('div');
    tooltipShadow.id = 'tooltipShadow';
			
   document.body.appendChild(tooltip);
   document.body.appendChild(tooltipShadow);
			
      if(tooltip_is_msie){
      iframe = document.createElement('iframe');
      iframe.frameborder='5';
      iframe.style.backgroundColor='#FFFFFF';
      iframe.src = '#';
      iframe.style.zIndex = 100;
      iframe.style.position = 'absolute';
      document.body.appendChild(iframe);
      }
			
   }
		
  tooltip.style.display='block';
  tooltipShadow.style.display='block';
  if(tooltip_is_msie)iframe.style.display='block';

  var st = Math.max(document.body.scrollTop,document.documentElement.scrollTop);
  if(navigator.userAgent.toLowerCase().indexOf('safari')>=0)st=0;
  var leftPos = e.clientX + 10;
		
  tooltip.style.width = null;	// Reset style width if it's set
  tooltip.innerHTML = tooltipTxt;
  tooltip.style.left = leftPos + 'px';
  tooltip.style.top = e.clientY + 10 + st + 'px';

  tooltipShadow.style.left =  leftPos + shadowSize + 'px';
  tooltipShadow.style.top = e.clientY + 10 + st + shadowSize + 'px';
		
  if(tooltip.offsetWidth>tooltipMaxWidth)
  {	/* Exceeding max width of tooltip ? */
    tooltip.style.width = tooltipMaxWidth + 'px';
  }
		
  var tooltipWidth = tooltip.offsetWidth;
  if(tooltipWidth<tooltipMinWidth)
  tooltipWidth = tooltipMinWidth;

  tooltip.style.width = tooltipWidth + 'px';
  tooltipShadow.style.width = tooltip.offsetWidth + 'px';
  tooltipShadow.style.height = tooltip.offsetHeight + 'px';
		
  if((leftPos + tooltipWidth)>bodyWidth)
  {
   tooltip.style.left = (tooltipShadow.style.left.replace('px','') - ((leftPos + tooltipWidth)-bodyWidth)) + 'px';
   tooltipShadow.style.left = (tooltipShadow.style.left.replace('px','') - ((leftPos + tooltipWidth)-bodyWidth) + shadowSize) + 'px';
  }
		
  if(tooltip_is_msie)
  {
   iframe.style.left = tooltip.style.left;
   iframe.style.top = tooltip.style.top;
   iframe.style.width = tooltip.offsetWidth + 'px';
   iframe.style.height = tooltip.offsetHeight + 'px';
  }

 }
	
 function hideTooltip()
 {
  tooltip.style.display='none';
  tooltipShadow.style.display='none';
  if(tooltip_is_msie)iframe.style.display='none';
 }
