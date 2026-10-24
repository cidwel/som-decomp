; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AECB
boss_lz_controls_dbaecb:
    ; backreference count 3, distance 75
    .byte $80, $4A
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
