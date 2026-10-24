; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D75F
boss_lz_controls_dbd75f:
    ; backreference count 3, distance 23
    .byte $80, $16
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
