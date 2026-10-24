; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $08D6
boss_lz_controls_db08d6:
    ; backreference count 8, distance 9
    .byte $D0, $08
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
