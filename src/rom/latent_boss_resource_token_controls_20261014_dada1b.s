; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DA1B
boss_lz_controls_dada1b:
    ; backreference count 3, distance 753
    .byte $82, $F0
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
