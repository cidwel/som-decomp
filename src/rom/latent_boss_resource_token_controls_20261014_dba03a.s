; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A03A
boss_lz_controls_dba03a:
    ; backreference count 3, distance 547
    .byte $82, $22
    ; backreference count 5, distance 93
    .byte $90, $5C
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
