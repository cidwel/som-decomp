; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D7AE
boss_lz_controls_dad7ae:
    ; backreference count 5, distance 12
    .byte $90, $0B
    ; literal count 21; subsequent asset bytes excluded
    .byte $14
