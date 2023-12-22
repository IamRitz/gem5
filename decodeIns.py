Tasks = {
        "MATCH_GCD" :  ("MASK_GCD", "R") ,
        "MATCH_FACT" : ("MASK_FACT", "U"),
        "MATCH_COMB" :  ("MASK_COMB", "R"), 
        # Define your own custom instruction name here
}

MATCH = {
        "MATCH_GCD" : bin(0x6027)[2:].zfill(32),
        "MATCH_FACT": bin(0x2b)[2:].zfill(32),
        "MATCH_COMB" : bin(0x200006b)[2:].zfill(32),
        # Define your own correspoding custom instruction's match value(hex)
}

MASK = {
        "MASK_GCD"  : bin(0xfe00707f)[2:].zfill(32),
        "MASK_FACT" : bin(0x7f)[2:].zfill(32),
        "MASK_COMB"  : bin(0xfe00707f)[2:].zfill(32),
        # Define your own correspoding custom instruction's mask value(hex)
}


def DecodeInst(num1, num2, mapping):

    num1_temp = int(num1, 2)
    num2_temp = int(num2, 2)

    num = num1_temp & num2_temp

    num = bin(num)[2:] 

    num = num.zfill(len(num1))


    for key, pair in mapping.items():
        res = num[len(num)-1-pair[1]:len(num)-pair[0]]
        print("{0} : {1} ({2}) ({3})".format(key, res, int(res, 2), hex(int(res, 2))))


for a, b in Tasks.items():
    # print(num1, hex(int(num1, 2)))
    # print(num2, hex(int(num2, 2)))

    # num1 = input("Enter MATCH bits: ").strip()
    # num2 = input("Enter MASK bits: ").strip()


    # For R-type Instruction (without immediate)
    # Refer this: https://github.com/gem5/gem5/blob/stable/src/arch/riscv/isa/bitfields.isa
    mapping_r = {
            "QUADRANT" : (0,1),
            "OPCODE5"  : (2,6),
            "RD"       : (7, 11),
            "FUNCT3"   : (12, 14),
            "RS1"      : (15, 19),
            "RS2"      : (20, 24),
            "FUNCT7"   : (25, 31)
    }


    # For UJ-type Instruction
    mapping_uj = {
            "QUADRANT" : (0,1),
            "OPCODE5"  : (2,6),
            "RD"       : (7, 11),
            "IMM"   : (12, 31),
    }

    num1 = MATCH[a]
    num2 = MASK[b[0]]

    inst_name = a[6:]
    inst_hex = hex(int(num1, 2))
    
    print(f"--------------------{inst_name}({inst_hex})--------------------")
    if(b[1] == "R"):
        DecodeInst(num1, num2, mapping_r)
    elif(b[1] == "U"):
        DecodeInst(num1, num2, mapping_uj)
    print("----------------------------------------------------------------")
