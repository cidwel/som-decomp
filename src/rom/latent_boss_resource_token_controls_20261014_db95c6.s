; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $95C6
boss_lz_controls_db95c6:
    ; backreference count 5, distance 8
    .byte $A0, $07
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
