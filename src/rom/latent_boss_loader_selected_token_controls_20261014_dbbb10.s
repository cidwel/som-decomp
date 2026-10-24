; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB10
boss_lz_controls_dbbb10:
    ; backreference count 3, distance 18
    .byte $80, $11
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
