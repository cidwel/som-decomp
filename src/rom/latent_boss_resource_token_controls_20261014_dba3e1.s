; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3E1
boss_lz_controls_dba3e1:
    ; backreference count 4, distance 453
    .byte $89, $C4
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
