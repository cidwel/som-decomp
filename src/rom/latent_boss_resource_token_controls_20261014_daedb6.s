; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EDB6
boss_lz_controls_daedb6:
    ; backreference count 3, distance 528
    .byte $82, $0F
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
