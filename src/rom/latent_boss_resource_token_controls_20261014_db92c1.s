; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $92C1
boss_lz_controls_db92c1:
    ; backreference count 9, distance 24
    .byte $E0, $17
    ; literal count 10; subsequent asset bytes excluded
    .byte $09
