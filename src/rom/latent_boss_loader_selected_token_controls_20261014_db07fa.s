; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07FA
boss_lz_controls_db07fa:
    ; backreference count 4, distance 431
    .byte $91, $AE
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
