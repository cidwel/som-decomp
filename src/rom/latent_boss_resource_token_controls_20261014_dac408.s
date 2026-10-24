; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $C408
boss_lz_controls_dac408:
    ; backreference count 3, distance 224
    .byte $80, $DF
    ; literal count 71; subsequent asset bytes excluded
    .byte $46
