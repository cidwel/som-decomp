; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2EA
boss_lz_controls_dad2ea:
    ; backreference count 3, distance 144
    .byte $80, $8F
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
