; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C0EA
boss_lz_controls_dac0ea:
    ; backreference count 3, distance 59
    .byte $80, $3A
    ; literal count 22; subsequent asset bytes excluded
    .byte $15
