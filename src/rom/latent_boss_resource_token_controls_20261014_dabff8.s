; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BFF8
boss_lz_controls_dabff8:
    ; backreference count 3, distance 391
    .byte $81, $86
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
