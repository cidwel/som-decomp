; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C160
boss_lz_controls_dac160:
    ; backreference count 3, distance 605
    .byte $82, $5C
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
