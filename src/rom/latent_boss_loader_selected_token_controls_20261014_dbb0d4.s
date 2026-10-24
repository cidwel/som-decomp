; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B0D4
boss_lz_controls_dbb0d4:
    ; backreference count 3, distance 150
    .byte $80, $95
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
