; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BAE5
boss_lz_controls_dbbae5:
    ; backreference count 3, distance 5
    .byte $80, $04
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
