; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B98D
boss_lz_controls_dbb98d:
    ; backreference count 4, distance 783
    .byte $87, $0E
    ; literal count 41; subsequent asset bytes excluded
    .byte $28
