; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A91D
boss_lz_controls_dba91d:
    ; backreference count 3, distance 571
    .byte $82, $3A
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
