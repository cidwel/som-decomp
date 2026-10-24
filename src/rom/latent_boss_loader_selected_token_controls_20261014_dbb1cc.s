; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B1CC
boss_lz_controls_dbb1cc:
    ; backreference count 3, distance 214
    .byte $80, $D5
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
