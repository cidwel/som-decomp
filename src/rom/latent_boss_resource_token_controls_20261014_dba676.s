; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A676
boss_lz_controls_dba676:
    ; backreference count 4, distance 23
    .byte $82, $16
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
