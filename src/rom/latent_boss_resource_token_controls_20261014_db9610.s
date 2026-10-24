; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9610
boss_lz_controls_db9610:
    ; backreference count 10, distance 997
    .byte $F3, $E4
    ; backreference count 8, distance 1
    .byte $D0, $00
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
