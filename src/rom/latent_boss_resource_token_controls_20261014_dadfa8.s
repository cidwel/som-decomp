; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DFA8
boss_lz_controls_dadfa8:
    ; backreference count 13, distance 1371
    .byte $D5, $5A
    ; backreference count 6, distance 1
    .byte $98, $00
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
