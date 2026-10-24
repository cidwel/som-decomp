; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C6DF
boss_lz_controls_dac6df:
    ; backreference count 3, distance 120
    .byte $80, $77
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
