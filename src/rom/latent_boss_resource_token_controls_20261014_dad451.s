; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D451
boss_lz_controls_dad451:
    ; backreference count 4, distance 128
    .byte $88, $7F
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
