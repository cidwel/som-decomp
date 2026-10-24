; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $079C
boss_lz_controls_db079c:
    ; backreference count 5, distance 1339
    .byte $A5, $3A
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
