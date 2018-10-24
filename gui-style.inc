#if defined GUI_style_included
	#endinput
#endif
#define GUI_style_included


#include <a_samp>
#include <YSI-Data\y_iterate>
#include <YSI-Core\y_utils>
#include <PawnPlus>
#include <YSI-Coding\y_hooks>


#if !defined MAX_GUI_STYLES
	#define MAX_GUI_STYLES 25
#endif

#define INVALID_GUI_STYLE_ID GUIStyle:-1


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


static Iterator:GUIStyles<MAX_GUI_STYLES>;
static Map:GUIStyleAttributes[GUIStyle:MAX_GUI_STYLES];


DEFINE_HOOK_REPLACEMENT(Attribute, Attr);

forward public OnGUIStyleAttributeChanged(GUIStyle:style_id, const attribute_name[]);
forward public OnGUIStyleDestroyed(GUIStyle:style_id);


stock GUIStyle:CreateGUIStyle() {
	new GUIStyle:id = GUIStyle:Iter_Free(GUIStyles);

	if (id == GUIStyle:cellmin) {
		return INVALID_GUI_STYLE_ID;
	}

	GUIStyleAttributes[id] = map_new();

	Iter_Add(GUIStyles, _:id);
	return id;
}


stock bool:IsValidGUIStyle(GUIStyle:id) {
	return Iter_Contains(GUIStyles, _:id);
}


stock bool:IsValidGUIStyleAttribute(GUIStyle:id, const attribute_name[]) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	return map_has_str_key(GUIStyleAttributes[id], attribute_name);
}


stock GUIStyleAttributeType:GetGUIStyleAttributeType(GUIStyle:id, const attribute_name[]) {
	if (!IsValidGUIStyleAttribute(id, attribute_name)) {
		return GUI_STYLE_ATTRIBUTE_NULL;
	}

	switch (map_str_sizeof(GUIStyleAttributes[id], attribute_name)) {
		case 2: {
			return GUI_STYLE_ATTRIBUTE_VECTOR2;
		}

		case 3: {
			return GUI_STYLE_ATTRIBUTE_VECTOR3;
		}

		case 4: {
			return GUI_STYLE_ATTRIBUTE_VECTOR4;
		}
	}

	new tag = map_str_tagof(GUIStyleAttributes[id], attribute_name);

	if (tag == tagof(Float:)) {
		return GUI_STYLE_ATTRIBUTE_FLOAT;
	}

	if (tag == tagof(bool:)) {
		return GUI_STYLE_ATTRIBUTE_BOOL;
	}

	if (tag == tagof(GlobalString:)) {
		return GUI_STYLE_ATTRIBUTE_STRING;
	}

	return GUI_STYLE_ATTRIBUTE_INT;
}


stock bool:RemoveGUIStyleAttribute(GUIStyle:id, const attribute_name[]) {
	switch (GetGUIStyleAttributeType(id, attribute_name)) {
		case GUI_STYLE_ATTRIBUTE_NULL: {
			return false;
		}

		case GUI_STYLE_ATTRIBUTE_STRING: {
			str_delete(GlobalString:map_str_get(GUIStyleAttributes[id], attribute_name));
		}
	}

	map_str_remove(GUIStyleAttributes[id], attribute_name);

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:SetGUIStyleAttributeBool(GUIStyle:id, const attribute_name[], bool:value) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	map_str_set(GUIStyleAttributes[id], attribute_name, value);

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:GetGUIStyleAttributeBool(GUIStyle:id, const attribute_name[], &bool:value) {
	if (GetGUIStyleAttributeType(id, attribute_name) != GUI_STYLE_ATTRIBUTE_BOOL) {
		return false;
	}

	value = bool:map_str_get(GUIStyleAttributes[id], attribute_name);
	return true;
}


stock bool:SetGUIStyleAttributeInt(GUIStyle:id, const attribute_name[], value) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	map_str_set(GUIStyleAttributes[id], attribute_name, value);

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:GetGUIStyleAttributeInt(GUIStyle:id, const attribute_name[], &value) {
	if (GetGUIStyleAttributeType(id, attribute_name) != GUI_STYLE_ATTRIBUTE_INT) {
		return false;
	}

	value = map_str_get(GUIStyleAttributes[id], attribute_name);
	return true;
}


stock bool:SetGUIStyleAttributeFloat(GUIStyle:id, const attribute_name[], Float:value) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	map_str_set(GUIStyleAttributes[id], attribute_name, value);

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:GetGUIStyleAttributeFloat(GUIStyle:id, const attribute_name[], &Float:value) {
	if (GetGUIStyleAttributeType(id, attribute_name) != GUI_STYLE_ATTRIBUTE_FLOAT) {
		return false;
	}

	value = Float:map_str_get(GUIStyleAttributes[id], attribute_name);
	return true;
}


stock bool:SetGUIStyleAttributeVector2(GUIStyle:id, const attribute_name[], Float:x, Float:y) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	new Float:value[2];

	value[0] = x;
	value[1] = y;

	map_str_set_arr(GUIStyleAttributes[id], attribute_name, value);

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:GetGUIStyleAttributeVector2(GUIStyle:id, const attribute_name[], &Float:x, &Float:y) {
	if (GetGUIStyleAttributeType(id, attribute_name) != GUI_STYLE_ATTRIBUTE_VECTOR2) {
		return false;
	}

	new Float:value[2];
	map_str_get_arr(GUIStyleAttributes[id], attribute_name, value);

	x = value[0];
	y = value[1];

	return true;
}


stock bool:SetGUIStyleAttributeVector3(GUIStyle:id, const attribute_name[], Float:x, Float:y, Float:z) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	new Float:value[3];

	value[0] = x;
	value[1] = y;
	value[2] = z;

	map_str_set_arr(GUIStyleAttributes[id], attribute_name, value);

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:GetGUIStyleAttributeVector3(GUIStyle:id, const attribute_name[], &Float:x, &Float:y, &Float:z) {
	if (GetGUIStyleAttributeType(id, attribute_name) != GUI_STYLE_ATTRIBUTE_VECTOR3) {
		return false;
	}

	new Float:value[3];
	map_str_get_arr(GUIStyleAttributes[id], attribute_name, value);

	x = value[0];
	y = value[1];
	z = value[2];

	return true;
}


stock bool:SetGUIStyleAttributeVector4(GUIStyle:id, const attribute_name[], Float:x, Float:y, Float:z, Float:a) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	new Float:value[4];

	value[0] = x;
	value[1] = y;
	value[2] = z;
	value[3] = a;

	map_str_set_arr(GUIStyleAttributes[id], attribute_name, value);

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:GetGUIStyleAttributeVector4(GUIStyle:id, const attribute_name[], &Float:x, &Float:y, &Float:z, &Float:a) {
	if (GetGUIStyleAttributeType(id, attribute_name) != GUI_STYLE_ATTRIBUTE_VECTOR4) {
		return false;
	}

	new Float:value[4];
	map_str_get_arr(GUIStyleAttributes[id], attribute_name, value);

	x = value[0];
	y = value[1];
	z = value[2];
	a = value[3];

	return true;
}


stock bool:SetGUIStyleAttributeString(GUIStyle:id, const attribute_name[], const value[]) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	map_str_set(GUIStyleAttributes[id], attribute_name, str_to_global(str_new(value)));

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:GetGUIStyleAttributeString(GUIStyle:id, const attribute_name[], value[], value_size = sizeof(value)) {
	if (GetGUIStyleAttributeType(id, attribute_name) != GUI_STYLE_ATTRIBUTE_STRING) {
		return false;
	}

	new GlobalString:temp = GlobalString:map_str_get(GUIStyleAttributes[id], attribute_name);

	str_get(temp, value, value_size);
	return true;
}


stock bool:SetGUIStyleAttributeString_s(GUIStyle:id, const attribute_name[], String:value) {
	if (isnull(attribute_name)) {
		return false;
	}

	if (!IsValidGUIStyle(id)) {
		return false;
	}

	map_str_set(GUIStyleAttributes[id], attribute_name, str_to_global(str_clone(value)));

	CallLocalFunction("OnGUIStyleAttributeChanged", "is", _:id, attribute_name);
	return true;
}


stock bool:GetGUIStyleAttributeString_s(GUIStyle:id, const attribute_name[], &String:value) {
	if (GetGUIStyleAttributeType(id, attribute_name) != GUI_STYLE_ATTRIBUTE_STRING) {
		return false;
	}

	value = String:map_str_get(GUIStyleAttributes[id], attribute_name);
	return true;
}


stock bool:DestroyGUIStyle(GUIStyle:id) {
	if (!IsValidGUIStyle(id)) {
		return false;
	}

	map_delete_deep(GUIStyleAttributes[id]);
	GUIStyleAttributes[id] = Map:0;

	Iter_Remove(GUIStyles, _:id);

	CallLocalFunction("OnGUIStyleDestroyed", "i", _:id);
	return true;
}
