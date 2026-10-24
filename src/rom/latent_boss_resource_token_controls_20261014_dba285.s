; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A285
boss_lz_controls_dba285:
    ; backreference count 3, distance 52
    .byte $80, $33
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
