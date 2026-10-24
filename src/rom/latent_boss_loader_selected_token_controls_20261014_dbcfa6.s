; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CFA6
boss_lz_controls_dbcfa6:
    ; backreference count 3, distance 431
    .byte $81, $AE
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
