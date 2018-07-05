#include "gui-style.inc"

#define RUN_TESTS
#include <YSI\y_testing>

Test:Main() {
    new GUIStyle:id = CreateGUIStyle();
    ASSERT(_:id != cellmin);

    SetGUIStyleAttributeBool(id, "asd", true);
    ASSERT(GetGUIStyleAttributeType(id, "asd") == GUI_STYLE_ATTRIBUTE_BOOL);

    new bool:bool_value;
    GetGUIStyleAttributeBool(id, "asd", bool_value);
    ASSERT(bool_value == true);

    SetGUIStyleAttributeInt(id, "coolness", 9000);
    ASSERT(GetGUIStyleAttributeType(id, "coolness") == GUI_STYLE_ATTRIBUTE_INT);

    new int_value;
    GetGUIStyleAttributeInt(id, "coolness", int_value);
    ASSERT(int_value == 9000);

    SetGUIStyleAttributeFloat(id, "blazeit", 4.20);
    ASSERT(GetGUIStyleAttributeType(id, "blazeit") == GUI_STYLE_ATTRIBUTE_FLOAT);

    new Float:float_value;
    GetGUIStyleAttributeFloat(id, "blazeit", float_value);
    ASSERT(float_value == 4.20);

    new Float:x, Float:y, Float:z, Float:a;

    SetGUIStyleAttributeVector2(id, "vector2", 1.0, 2.0);
    ASSERT(GetGUIStyleAttributeType(id, "vector2") == GUI_STYLE_ATTRIBUTE_VECTOR2);

    GetGUIStyleAttributeVector2(id, "vector2", x, y);
    ASSERT(x == 1.0);
    ASSERT(y == 2.0);

    SetGUIStyleAttributeVector3(id, "vector3", 3.0, 4.0, 5.0);
    ASSERT(GetGUIStyleAttributeType(id, "vector3") == GUI_STYLE_ATTRIBUTE_VECTOR3);

    GetGUIStyleAttributeVector3(id, "vector3", x, y, z);
    ASSERT(x == 3.0);
    ASSERT(y == 4.0);
    ASSERT(z == 5.0);

    SetGUIStyleAttributeVector4(id, "vector4", 6.0, 7.0, 8.0, 9.0);
    ASSERT(GetGUIStyleAttributeType(id, "vector4") == GUI_STYLE_ATTRIBUTE_VECTOR4);

    GetGUIStyleAttributeVector4(id, "vector4", x, y, z, a);
    ASSERT(x == 6.0);
    ASSERT(y == 7.0);
    ASSERT(z == 8.0);
    ASSERT(a == 9.0);

    SetGUIStyleAttributeString(id, "itscominghome", "obviously");
    ASSERT(GetGUIStyleAttributeType(id, "itscominghome") == GUI_STYLE_ATTRIBUTE_STRING);

    new buffer[32];
    GetGUIStyleAttributeString(id, "itscominghome", buffer);
    ASSERT(!strcmp(buffer, "obviously"));

    SetGUIStyleAttributeString_s(id, "asd", str_new("asd"));
    ASSERT(GetGUIStyleAttributeType(id, "asd") == GUI_STYLE_ATTRIBUTE_STRING);

    new String:asd;
    GetGUIStyleAttributeString_s(id, "asd", asd);
    ASSERT(str_equal(asd, str_new("asd")));

    DestroyGUIStyle(id);
    ASSERT(IsValidGUIStyle(id) == false);
}
