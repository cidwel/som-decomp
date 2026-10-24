; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7E9
boss_lz_controls_dad7e9:
    ; backreference count 4, distance 99
    .byte $88, $62
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
