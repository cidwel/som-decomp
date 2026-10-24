; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B3B4
boss_lz_controls_dbb3b4:
    ; backreference count 3, distance 103
    .byte $80, $66
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
