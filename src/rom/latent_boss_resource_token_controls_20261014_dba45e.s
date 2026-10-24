; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A45E
boss_lz_controls_dba45e:
    ; backreference count 4, distance 62
    .byte $88, $3D
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
