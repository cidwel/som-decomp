; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D711
boss_lz_controls_dad711:
    ; backreference count 4, distance 1033
    .byte $8C, $08
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
