; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F3B9
boss_lz_controls_daf3b9:
    ; backreference count 3, distance 1981
    .byte $87, $BC
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
