; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C9CA
boss_lz_controls_dac9ca:
    ; backreference count 4, distance 1547
    .byte $8E, $0A
    ; backreference count 8, distance 403
    .byte $A9, $92
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
