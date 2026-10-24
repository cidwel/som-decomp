; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A02D
boss_lz_controls_dba02d:
    ; backreference count 3, distance 870
    .byte $83, $65
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
