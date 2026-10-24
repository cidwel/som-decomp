; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B9B9
boss_lz_controls_dbb9b9:
    ; backreference count 3, distance 404
    .byte $81, $93
    ; literal count 54; subsequent asset bytes excluded
    .byte $35
