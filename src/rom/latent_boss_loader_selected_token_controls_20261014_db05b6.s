; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05B6
boss_lz_controls_db05b6:
    ; backreference count 5, distance 794
    .byte $A3, $19
    ; backreference count 3, distance 107
    .byte $80, $6A
    ; backreference count 4, distance 202
    .byte $90, $C9
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
