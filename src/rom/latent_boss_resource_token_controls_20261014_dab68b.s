; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B68B
boss_lz_controls_dab68b:
    ; backreference count 4, distance 59
    .byte $84, $3A
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
