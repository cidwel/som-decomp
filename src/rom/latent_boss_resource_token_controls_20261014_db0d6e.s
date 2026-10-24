; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0D6E
boss_lz_controls_db0d6e:
    ; backreference count 26, distance 14
    .byte $AE, $0D
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
