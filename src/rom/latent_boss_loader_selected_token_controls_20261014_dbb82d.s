; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B82D
boss_lz_controls_dbb82d:
    ; backreference count 4, distance 12
    .byte $84, $0B
    ; literal count 103; subsequent asset bytes excluded
    .byte $66
