; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0B87
boss_lz_controls_db0b87:
    ; backreference count 5, distance 15
    .byte $A0, $0E
    ; backreference count 5, distance 27
    .byte $A0, $1A
    ; backreference count 3, distance 35
    .byte $80, $22
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
