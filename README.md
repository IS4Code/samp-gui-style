# GUI Style

[![sampctl](https://shields.southcla.ws/badge/sampctl-gui--style-2f2f2f.svg?style=for-the-badge)](https://github.com/kristoisberg/gui-style)

This library will probably not be useful for other people, but it will be a dependency of my upcoming GUI framework. It provides an easy way of creating GUI element styles and modifying their attributes.


## Installation

Simply install to your project:

```bash
sampctl package install kristoisberg/gui-style
```

Include in your code and begin using the library:

```pawn
#include <gui-style>
```

## Usage


### Functions

```pawn
stock GUIStyle:CreateGUIStyle();
stock bool:IsValidGUIStyle(GUIStyle:style_id);
stock bool:DestroyGUIStyle(GUIStyle:style_id);
stock GUIStyleAttributeType:GetGUIStyleAttributeType(GUIStyle:style_id, const attribute_name[], size = sizeof(attribute_name));
stock bool:SetGUIStyleAttributeBool(GUIStyle:style_id, const attribute_name[], bool:value, size = sizeof(attribute_name));
stock bool:GetGUIStyleAttributeBool(GUIStyle:style_id, const attribute_name[], &bool:value, size = sizeof(attribute_name));
stock bool:SetGUIStyleAttributeInt(GUIStyle:style_id, const attribute_name[], value, size = sizeof(attribute_name));
stock bool:GetGUIStyleAttributeInt(GUIStyle:style_id, const attribute_name[], &value, size = sizeof(attribute_name));
stock bool:SetGUIStyleAttributeFloat(GUIStyle:style_id, const attribute_name[], Float:value, size = sizeof(attribute_name));
stock bool:GetGUIStyleAttributeFloat(GUIStyle:style_id, const attribute_name[], &Float:value, size = sizeof(attribute_name));
stock bool:SetGUIStyleAttributeVector2(GUIStyle:style_id, const attribute_name[], Float:x, Float:y, size = sizeof(attribute_name));
stock bool:GetGUIStyleAttributeVector2(GUIStyle:style_id, const attribute_name[], &Float:x, &Float:y, size = sizeof(attribute_name));
stock bool:SetGUIStyleAttributeVector3(GUIStyle:style_id, const attribute_name[], Float:x, Float:y, Float:z, size = sizeof(attribute_name));
stock bool:GetGUIStyleAttributeVector3(GUIStyle:style_id, const attribute_name[], &Float:x, &Float:y, &Float:z, size = sizeof(attribute_name));
stock bool:SetGUIStyleAttributeVector4(GUIStyle:style_id, const attribute_name[], Float:x, Float:y, Float:z, Float:a, size = sizeof(attribute_name));
stock bool:GetGUIStyleAttributeVector4(GUIStyle:style_id, const attribute_name[], &Float:x, &Float:y, &Float:z, &Float:a, size = sizeof(attribute_name));
stock bool:SetGUIStyleAttributeString(GUIStyle:style_id, const attribute_name[], const value[], value_size = sizeof(value), attribute_size = sizeof(attribute_name));
stock bool:GetGUIStyleAttributeString(GUIStyle:style_id, const attribute_name[], value[], value_size = sizeof(value), attribute_size = sizeof(attribute_name));
stock bool:SetGUIStyleAttributeString_s(GUIStyle:style_id, const attribute_name[], String:value, size = sizeof(attribute_name));
stock bool:GetGUIStyleAttributeString_s(GUIStyle:style_id, const attribute_name[], &String:value, size = sizeof(attribute_name));
```


### Callbacks

```pawn
forward public OnGUIStyleAttributeChange(GUIStyle:style_id, const attribute_name[]);
```


### Data types

```pawn
enum GUIStyleAttributeType {
	GUI_STYLE_ATTRIBUTE_NULL,
	GUI_STYLE_ATTRIBUTE_BOOL,
	GUI_STYLE_ATTRIBUTE_INT,
	GUI_STYLE_ATTRIBUTE_FLOAT,
	GUI_STYLE_ATTRIBUTE_STRING,
	GUI_STYLE_ATTRIBUTE_VECTOR2,
	GUI_STYLE_ATTRIBUTE_VECTOR3,
	GUI_STYLE_ATTRIBUTE_VECTOR4
};
```


## Testing

To test, simply run the package:

```bash
sampctl package run
```
