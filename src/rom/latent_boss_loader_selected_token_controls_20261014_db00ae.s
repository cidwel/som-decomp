; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00AE
boss_lz_controls_db00ae:
    ; backreference count 3, distance 7
    .byte $80, $06
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
