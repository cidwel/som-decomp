; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAB1
boss_lz_controls_dbcab1:
    ; backreference count 3, distance 207
    .byte $80, $CE
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
