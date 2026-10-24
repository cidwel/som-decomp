; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F36E
boss_lz_controls_daf36e:
    ; backreference count 3, distance 1535
    .byte $85, $FE
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
