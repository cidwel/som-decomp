; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B21C
boss_lz_controls_dbb21c:
    ; backreference count 3, distance 13
    .byte $80, $0C
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 41; subsequent asset bytes excluded
    .byte $28
