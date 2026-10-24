; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D74E
boss_lz_controls_dbd74e:
    ; backreference count 3, distance 11
    .byte $80, $0A
    ; literal count 14; subsequent asset bytes excluded
    .byte $0D
