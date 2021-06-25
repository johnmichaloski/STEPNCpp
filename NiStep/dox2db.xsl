<!-- $Id: dox2db.xsl,v 1.1.1.1 2009/07/27 21:29:41 michalos Exp $  -->

<xsl:stylesheet version   = "1.0"
		xmlns:xsl = "http://www.w3.org/1999/XSL/Transform"
		xmlns:fo  = "http://www.w3.org/1999/XSL/Format">
  

  <xsl:template match ="doxygen">

    <article>
      <artheader>
	<title>Doxygen to DocBook via XML</title>
	<author><firstname>Hunter</firstname>
          <surname>Marshall</surname></author>
      </artheader>
      <!-- Here's where it all happens -->
      <xsl:apply-templates/> 
    </article>
  </xsl:template>
  

  <!-- ***************************
  These are the constituent templates 
  ******************************** -->
  <!-- New page for new compound -->
  <xsl:template match ="compoundname">
    <sect1><title>
	<xsl:value-of select="."/>
	Compound Reference
      </title>
      <xsl:apply-templates select = "../detaileddescription" 
			   mode   = "move" />
    </sect1>
  </xsl:template>
  
  <!-- ***************************************
  These next 2 templates illustrate how to change the order 
  of xml information in the final representation.
  ******************************************** -->
  <!-- Using "mode" to differentiate the use of this
  template from the default, insert compound detailed desc 
  after compound title (see previous template) -->
  <xsl:template match = "compounddef/detaileddescription"
		mode  = "move" >
    <sect2><title>
	Detailed Description </title>
      <xsl:apply-templates/>
    </sect2>
  </xsl:template>

  <!-- The null template so that nothing is rendered when the 
  node processing arrives at that part of the xml doc -->
  <xsl:template match = "compounddef/detaileddescription">
  </xsl:template>

  <!-- One possible way of dealing with achieving output
  similar to present doxygen where the grouping of elements 
  is according to the value of the "kind" attribute -->
  <xsl:template match ="sectiondef">
    <sect2><title>
	<xsl:if test="@kind='public-attrib'">
	  Public Attributes
	</xsl:if>
	<xsl:if test="@kind='public-func'">
	  Public Functions
	</xsl:if>
      </title>
      <programlisting>
	<xsl:apply-templates/>
      </programlisting>
    </sect2>
  </xsl:template>

  <!-- *******************************
  The remaining templates are either null (to suppress output) or 
  invoke the default template which just dumps element (and attribute
  I think) info
  ************************************ --> 
  <xsl:template match ="memberdef">
      <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match ="memberdef/type">
    <type>
      <xsl:value-of select="."/>
    </type>
  </xsl:template>

  <xsl:template match ="memberdef/name">
    <varname>
      <xsl:value-of select="."/>
    </varname>
  </xsl:template>



  <xsl:template match ="briefdescription">
  </xsl:template>

  <xsl:template match ="detaileddescription">
  </xsl:template>

  <xsl:template match ="location">
  </xsl:template>

  <xsl:template match ="collaborationgraph">
  </xsl:template>

  <xsl:template match ="sourcecode">
  </xsl:template>


</xsl:stylesheet>

<!-- 
$Log: dox2db.xsl,v $
Revision 1.1.1.1  2009/07/27 21:29:41  michalos
Initial STEPNC++ COM Files

Revision 1.2  2001/10/26 16:28:07  hmarshall
comment

Revision 1.1  2001/10/26 16:25:42  hmarshall
Initial try.

-->
