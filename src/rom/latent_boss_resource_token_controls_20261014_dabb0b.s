; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB0B
boss_lz_controls_dabb0b:
    ; backreference count 5, distance 33
    .byte $88, $20
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
