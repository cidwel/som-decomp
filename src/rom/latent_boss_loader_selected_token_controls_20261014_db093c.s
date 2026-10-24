; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $093C
boss_lz_controls_db093c:
    ; backreference count 5, distance 1037
    .byte $A4, $0C
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
