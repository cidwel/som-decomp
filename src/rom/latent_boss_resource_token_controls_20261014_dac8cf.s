; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C8CF
boss_lz_controls_dac8cf:
    ; backreference count 3, distance 166
    .byte $80, $A5
    ; literal count 70; subsequent asset bytes excluded
    .byte $45
