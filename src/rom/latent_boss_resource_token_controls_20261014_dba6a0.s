; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A6A0
boss_lz_controls_dba6a0:
    ; backreference count 4, distance 4
    .byte $84, $03
    ; literal count 85; subsequent asset bytes excluded
    .byte $54
