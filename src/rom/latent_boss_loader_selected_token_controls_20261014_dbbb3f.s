; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB3F
boss_lz_controls_dbbb3f:
    ; backreference count 23, distance 1
    .byte $D0, $00
    ; literal count 31; subsequent asset bytes excluded
    .byte $1E
