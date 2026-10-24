; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7CF
boss_lz_controls_dab7cf:
    ; backreference count 6, distance 308
    .byte $8D, $33
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
