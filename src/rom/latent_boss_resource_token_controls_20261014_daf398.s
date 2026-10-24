; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F398
boss_lz_controls_daf398:
    ; backreference count 10, distance 3251
    .byte $FC, $B2
    ; backreference count 10, distance 3251
    .byte $FC, $B2
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
