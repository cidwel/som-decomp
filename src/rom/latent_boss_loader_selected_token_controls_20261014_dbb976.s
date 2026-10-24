; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B976
boss_lz_controls_dbb976:
    ; backreference count 3, distance 101
    .byte $80, $64
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
