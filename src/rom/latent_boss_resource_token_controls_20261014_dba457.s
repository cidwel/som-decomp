; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A457
boss_lz_controls_dba457:
    ; backreference count 3, distance 95
    .byte $80, $5E
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
