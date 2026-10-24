; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A317
boss_lz_controls_dba317:
    ; backreference count 3, distance 63
    .byte $80, $3E
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
