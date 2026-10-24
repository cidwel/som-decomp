; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A04E
boss_lz_controls_dba04e:
    ; backreference count 3, distance 66
    .byte $80, $41
    ; literal count 8; subsequent asset bytes excluded
    .byte $07
