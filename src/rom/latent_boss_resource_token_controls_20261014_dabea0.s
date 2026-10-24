; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BEA0
boss_lz_controls_dabea0:
    ; backreference count 3, distance 136
    .byte $80, $87
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
