; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B108
boss_lz_controls_dbb108:
    ; backreference count 9, distance 50
    .byte $98, $31
    ; backreference count 3, distance 644
    .byte $82, $83
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
