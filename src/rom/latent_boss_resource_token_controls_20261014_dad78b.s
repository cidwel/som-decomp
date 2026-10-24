; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D78B
boss_lz_controls_dad78b:
    ; backreference count 3, distance 1204
    .byte $84, $B3
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
