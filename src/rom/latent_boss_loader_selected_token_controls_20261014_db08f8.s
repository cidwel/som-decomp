; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08F8
boss_lz_controls_db08f8:
    ; backreference count 7, distance 874
    .byte $C3, $69
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
