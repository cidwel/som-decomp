; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $040A
boss_lz_controls_db040a:
    ; backreference count 5, distance 6
    .byte $A0, $05
    ; backreference count 3, distance 90
    .byte $80, $59
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
