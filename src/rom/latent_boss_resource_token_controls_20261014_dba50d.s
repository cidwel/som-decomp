; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A50D
boss_lz_controls_dba50d:
    ; backreference count 32, distance 1
    .byte $BA, $00
    ; literal count 68; subsequent asset bytes excluded
    .byte $43
