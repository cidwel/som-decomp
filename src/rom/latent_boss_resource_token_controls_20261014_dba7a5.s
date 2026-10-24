; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A7A5
boss_lz_controls_dba7a5:
    ; backreference count 3, distance 285
    .byte $81, $1C
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
