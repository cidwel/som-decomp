; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BF27
boss_lz_controls_dabf27:
    ; backreference count 3, distance 431
    .byte $81, $AE
    ; literal count 40; subsequent asset bytes excluded
    .byte $27
