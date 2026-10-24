; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $944A
boss_lz_controls_db944a:
    ; backreference count 3, distance 36
    .byte $80, $23
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
