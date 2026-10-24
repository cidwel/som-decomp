; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CA61
boss_lz_controls_dbca61:
    ; backreference count 3, distance 151
    .byte $80, $96
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
