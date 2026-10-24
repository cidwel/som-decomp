; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CE11
boss_lz_controls_dace11:
    ; backreference count 3, distance 39
    .byte $80, $26
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
