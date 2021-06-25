<!-- $Id: test.xsl,v 1.1.1.1 2009/07/27 21:29:36 michalos Exp $  -->

<xsl:stylesheet version   = "1.0"
		xmlns:xsl = "http://www.w3.org/1999/XSL/Transform"
		xmlns:fo  = "http://www.w3.org/1999/XSL/Format">
  
  <xsl:template match ="doxygen">
    <fo:root xmlns:fo="http://www.w3.org/1999/XSL/Format">
      
      <!-- defines page layout -->
      <fo:layout-master-set>
	<fo:simple-page-master master-name="simple"
			       page-height="29.7cm" 
			       page-width="21cm"
			       margin-top="1.5cm" 
			       margin-bottom="1.5cm" 
			       margin-left="2.5cm" 
			       margin-right="2.5cm">
	  <fo:region-body margin-top="1.5cm"/>
	  <fo:region-before extent="1.5cm"/>
	  <fo:region-after extent="1.5cm"/>
	</fo:simple-page-master>
      </fo:layout-master-set>
      
      <fo:page-sequence master-name="simple">
	<fo:flow flow-name="xsl-region-body">
	  <fo:block font-size="18pt" 
		    font-family="sans-serif" 
		    line-height="24pt"
		    space-after.optimum="15pt"
		    background-color="blue"
		    color="white"
		    text-align="center">
	    Hunter's Kick-Butt XSL Sample
	  </fo:block>
	  
	  <!-- Here's where it all happens -->
	  <xsl:apply-templates/> 

	</fo:flow>
      </fo:page-sequence>
    </fo:root>
  </xsl:template>


  <!-- ***************************
  These are the constituent templates 
  ******************************** -->
  <!-- New page for new compound -->
  <xsl:template match ="compoundname">
    <fo:block break-before ="page"
	      font-size    ="18pt"
	      space-after  ="12pt"
	      >
      <xsl:value-of select="."/>
      Compound Reference
    </fo:block>
    <fo:block space-after ="8pt">
      <xsl:apply-templates select = "../detaileddescription" 
			   mode   = "move" />
    </fo:block>
  </xsl:template>

  <!-- ***************************************
  These next 2 templates illustrate how to change the order 
  of xml information in the final representation
  ******************************************** -->
  <!-- Using "mode" to differentiate the use of this
  template from the default, insert compound detailed desc 
  after compound title (see previous template) -->
  <xsl:template match = "compounddef/detaileddescription"
		mode  = "move" >
    <fo:block font-size   = "15pt"  >
      Detailed Description
    </fo:block>
    <fo:block>
      <xsl:apply-templates/>
    </fo:block>
  </xsl:template>

  <!-- The null template so that nothing is rendered when the 
  node processing arrives at that part of the xml doc -->
  <xsl:template match = "compounddef/detaileddescription">
  </xsl:template>

  <!-- One possible way of dealing with achieving output
  similar to present doxygen where the grouping of elements 
  is according to the value of the "kind" attribute -->
  <xsl:template match ="sectiondef">
    <fo:block font-size   ="15pt"  
	      space-after ="6pt" >
      <xsl:if test="@kind='public-attrib'">
      Public Attributes
      </xsl:if>
      <xsl:if test="@kind='public-func'">
      Public Functions
      </xsl:if>
      <xsl:apply-templates/>
    </fo:block>
  </xsl:template>

<!-- *******************************
  The remaining templates are either null (to suppress output) or 
  invoke the default template which just dumps element (and attribute
  I think) info
 ************************************ --> 
  <xsl:template match ="memberdef">
    <fo:block font-size="12pt">
      <xsl:apply-templates/>
    </fo:block>
  </xsl:template>

  <xsl:template match ="briefdescription">
    <fo:block>
    </fo:block>
  </xsl:template>

  <xsl:template match ="detaileddescription">
    <fo:block>
    </fo:block>
  </xsl:template>

  <xsl:template match ="location">
    <fo:block>
    </fo:block>
  </xsl:template>

  <xsl:template match ="collaborationgraph">
    <fo:block>
    </fo:block>
  </xsl:template>

  <xsl:template match ="sourcecode">
    <fo:block>
    </fo:block>
  </xsl:template>


</xsl:stylesheet>

<!-- 
$Log: test.xsl,v $
Revision 1.1.1.1  2009/07/27 21:29:36  michalos
Initial STEPNC++ COM Files

Revision 1.4  2001/10/26 16:28:07  hmarshall
comment

Revision 1.3  2001/10/25 18:03:45  hmarshall
comments, tested/produced 205 page doc

Revision 1.2  2001/10/25 00:08:20  hmarshall
remove numbering

Revision 1.1  2001/10/24 19:07:41  hmarshall
The initial doxygen xsl file and a test xml file.
 
-->
