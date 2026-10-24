; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E10B
boss_lz_controls_dae10b:
    ; backreference count 5, distance 224
    .byte $90, $DF
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
