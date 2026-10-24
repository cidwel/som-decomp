; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $09C9
boss_lz_controls_db09c9:
    ; backreference count 4, distance 188
    .byte $90, $BB
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
