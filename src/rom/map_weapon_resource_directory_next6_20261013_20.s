; Sparse typed weapon resource headers; pointed graphics/frame data excluded.
.setcpu "65816"
.segment "CODE"
.org $C080
.macro weapon_resource tile_unit_index, frame_index_near_pointer
    .word tile_unit_index, frame_index_near_pointer
.endmacro
weapon_resource_selector_20:
    weapon_resource $0336, $42B2
weapon_resource_selector_21:
    weapon_resource $0190, $4328
weapon_resource_selector_22:
    weapon_resource $01C2, $4380
weapon_resource_selector_23:
    weapon_resource $01FF, $43C6
weapon_resource_selector_24:
    weapon_resource $01FF, $43EA
weapon_resource_selector_25:
    weapon_resource $01F6, $4406
weapon_resource_selector_26:
    weapon_resource $01FF, $445E
weapon_resource_selector_27:
    weapon_resource $04C3, $4482
weapon_resource_selector_28:
    weapon_resource $019A, $44C0
weapon_resource_selector_29:
    weapon_resource $01FF, $455C
weapon_resource_selector_2a:
    weapon_resource $004E, $4578
weapon_resource_selector_2b:
    weapon_resource $01FF, $45D4
weapon_resource_selector_2c:
    weapon_resource $01FF, $45F8
weapon_resource_selector_2d:
    weapon_resource $01FF, $4616
weapon_resource_selector_2e:
    weapon_resource $01FF, $4656
weapon_resource_selector_2f:
    weapon_resource $0553, $46DA
weapon_resource_selector_30:
    weapon_resource $01FF, $4736
weapon_resource_selector_31:
    weapon_resource $01FF, $4766
weapon_resource_selector_32:
    weapon_resource $01C2, $478C
weapon_resource_selector_33:
    weapon_resource $01FF, $47D6
weapon_resource_selector_34:
    weapon_resource $01FF, $47FC
weapon_resource_selector_35:
    weapon_resource $0030, $486C
weapon_resource_selector_36:
    weapon_resource $01FF, $4140
weapon_resource_selector_37:
    weapon_resource $01FF, $4902
weapon_resource_selector_38:
    weapon_resource $01FF, $4920
weapon_resource_selector_39:
    weapon_resource $0156, $4944
weapon_resource_selector_3a:
    weapon_resource $01FF, $4990
weapon_resource_selector_3b:
    weapon_resource $01FF, $49D6
weapon_resource_selector_3c:
    weapon_resource $0156, $49F4
weapon_resource_selector_3d:
    weapon_resource $008C, $4A34
weapon_resource_selector_3e:
    weapon_resource $01FF, $4A80
weapon_resource_selector_3f:
    weapon_resource $0000, $4AA8
weapon_resource_selector_40:
    weapon_resource $01FF, $4B06
weapon_resource_selector_41:
    weapon_resource $01C2, $4B3A
weapon_resource_selector_42:
    weapon_resource $04C3, $49F4
weapon_resource_selector_43:
    weapon_resource $067A, $4380
weapon_resource_selector_44:
    weapon_resource $0336, $44C0
weapon_resource_selector_45:
    weapon_resource $00C4, $4684
weapon_resource_selector_46:
    weapon_resource $0130, $4578
