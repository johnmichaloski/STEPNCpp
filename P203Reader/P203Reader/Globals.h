///
// Globals.h
//
#pragma once

#include "ap203SchemaDeclarations.h"
#include "ap203ClassDefinitions.h"
#include "Part21Generator.h"

class CPart21Generator;
extern CPart21Generator * _gPart21gen;
extern CString gStartEntity;

// TODO:
// 1) need to create & assign  _gPart21gen in mainfrm
//  mainfrm.h : 	CPart21Generator _part21gen;
//	mainfrm.cpp: in OnCreate() add _gPart21gen= &this->_part21gen;
//  mainfrm.cpp : add CPart21Generator * _gPart21gen=NULL;
// 2) name the starting entity - should only be one.
