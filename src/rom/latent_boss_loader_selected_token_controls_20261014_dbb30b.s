; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B30B
boss_lz_controls_dbb30b:
    ; backreference count 6, distance 363
    .byte $8D, $6A
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
