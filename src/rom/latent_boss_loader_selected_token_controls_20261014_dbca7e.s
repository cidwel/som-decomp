; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA7E
boss_lz_controls_dbca7e:
    ; backreference count 3, distance 14
    .byte $80, $0D
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
