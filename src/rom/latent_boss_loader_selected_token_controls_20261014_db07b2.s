; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $07B2
boss_lz_controls_db07b2:
    ; backreference count 9, distance 45
    .byte $E0, $2C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
