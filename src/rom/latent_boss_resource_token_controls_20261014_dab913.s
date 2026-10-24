; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B913
boss_lz_controls_dab913:
    ; backreference count 11, distance 12
    .byte $A0, $0B
    ; literal count 23; subsequent asset bytes excluded
    .byte $16
