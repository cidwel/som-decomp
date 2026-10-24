; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C169
boss_lz_controls_dac169:
    ; backreference count 3, distance 127
    .byte $80, $7E
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
