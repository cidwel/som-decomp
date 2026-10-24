; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A423
boss_lz_controls_dba423:
    ; backreference count 3, distance 108
    .byte $80, $6B
    ; backreference count 4, distance 1313
    .byte $8D, $20
    ; backreference count 3, distance 988
    .byte $83, $DB
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
