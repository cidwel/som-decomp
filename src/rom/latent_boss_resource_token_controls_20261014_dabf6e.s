; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF6E
boss_lz_controls_dabf6e:
    ; backreference count 4, distance 598
    .byte $86, $55
    ; literal count 9; subsequent asset bytes excluded
    .byte $08
