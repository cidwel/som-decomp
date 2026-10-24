; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B6AB
boss_lz_controls_dab6ab:
    ; backreference count 3, distance 111
    .byte $80, $6E
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
