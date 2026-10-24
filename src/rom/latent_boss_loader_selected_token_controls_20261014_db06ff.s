; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $06FF
boss_lz_controls_db06ff:
    ; backreference count 4, distance 1041
    .byte $94, $10
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
