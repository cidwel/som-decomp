; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B9F2
boss_lz_controls_dbb9f2:
    ; backreference count 3, distance 101
    .byte $80, $64
    ; literal count 34; subsequent asset bytes excluded
    .byte $21
