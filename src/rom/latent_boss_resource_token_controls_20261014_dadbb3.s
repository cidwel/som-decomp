; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DBB3
boss_lz_controls_dadbb3:
    ; backreference count 3, distance 221
    .byte $80, $DC
    ; literal count 35; subsequent asset bytes excluded
    .byte $22
