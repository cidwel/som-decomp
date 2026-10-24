; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B0C1
boss_lz_controls_dbb0c1:
    ; backreference count 3, distance 655
    .byte $82, $8E
    ; backreference count 4, distance 780
    .byte $87, $0B
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
