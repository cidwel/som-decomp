; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AEFE
boss_lz_controls_dbaefe:
    ; backreference count 4, distance 129
    .byte $84, $80
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
