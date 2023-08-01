#########################################################
# Copyright 2022 Pegasus Technology Holdings, Inc.
#
#########################################################

import re


def convert_first_letter_lower(str):
    s1 = list(str)
    s1[0] = s1[0].lower()
    s = ''.join(s1)
    return s


def convert_first_letter_upper(str):
    s1 = list(str)
    s1[0] = s1[0].upper()
    s = ''.join(s1)
    return s


def remove_underline(str_):
    # delete blank
    var_str = str_

    str = ""
    if var_str.find(' ') > 0:
        var_blank = var_str.split(" ")
        m = 0
        # print(var_str)
        for i in var_blank:
            var_blank[m] = i[0].upper() + i[1:]
            m = m + 1
        str = str.join(var_blank)
        # print(str)
    else:
        str = str_
    # check "_"
    if str.find('_') < 0:
        # print("remove: " + str_)
        return str

    return_str = ""
    var_name = str.split("_")
    index = 0
    for i in var_name:
        var_name[index] = i[0].upper() + i[1:].lower()
        index = index + 1
    return_str = return_str.join(var_name)
    return return_str

    # enum type var


def convert_upper_to_underline(str_):
    str = re.sub('(?<!^)(?=[A-Z])', '_', str_)
    return str


def type_convert(str):
    if str == "UInt64":
        returntype = "uint64_t"
    elif str == "UInt32":
        returntype = "uint32_t"
    elif str == "UInt16":
        returntype = "uint16_t"
    elif str == "UInt8":
        returntype = "uint8_t"
    elif str == "Int64":
        returntype = "int64_t"
    elif str == "Int64":
        returntype = "int64_t"
    elif str == "Int32":
        returntype = "int32_t"
    elif str == "Int16":
        returntype = "int16_t"
    elif str == "Int16":
        returntype = "int16_t"
    elif str == "Int8":
        returntype = "int8_t"
    elif str == "Bool":
        returntype = "bool"
    elif str == "Void":
        returntype = "void"
    elif str == "Float32":
        returntype = "float"
    elif str == "Float64":
        returntype = "double"
    else:
        returntype = ""
    return returntype


def get_enum_namespace(protocol_name, enum_name):
    return protocol_name + "::" + enum_name + "Type"
