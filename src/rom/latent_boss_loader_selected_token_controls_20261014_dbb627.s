; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B627
boss_lz_controls_dbb627:
    ; backreference count 3, distance 44
    .byte $80, $2B
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
