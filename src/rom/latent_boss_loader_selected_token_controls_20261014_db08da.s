; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08DA
boss_lz_controls_db08da:
    ; backreference count 6, distance 9
    .byte $B0, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
