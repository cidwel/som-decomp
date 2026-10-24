; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B043
boss_lz_controls_dbb043:
    ; backreference count 20, distance 630
    .byte $C6, $75
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
