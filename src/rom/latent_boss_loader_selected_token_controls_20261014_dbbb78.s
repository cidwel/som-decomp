; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB78
boss_lz_controls_dbbb78:
    ; backreference count 3, distance 226
    .byte $80, $E1
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
