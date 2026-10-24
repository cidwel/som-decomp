; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9B6F
boss_lz_controls_db9b6f:
    ; backreference count 4, distance 1
    .byte $88, $00
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
