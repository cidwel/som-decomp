; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BBC9
boss_lz_controls_dabbc9:
    ; backreference count 23, distance 1
    .byte $D0, $00
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
