; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BDD7
boss_lz_controls_dbbdd7:
    ; backreference count 4, distance 95
    .byte $88, $5E
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
