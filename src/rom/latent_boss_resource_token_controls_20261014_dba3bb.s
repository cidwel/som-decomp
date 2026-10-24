; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A3BB
boss_lz_controls_dba3bb:
    ; backreference count 4, distance 456
    .byte $89, $C7
    ; literal count 18; subsequent asset bytes excluded
    .byte $11
