; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9940
boss_lz_controls_db9940:
    ; backreference count 8, distance 45
    .byte $D0, $2C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
