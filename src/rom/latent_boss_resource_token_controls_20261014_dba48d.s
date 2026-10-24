; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A48D
boss_lz_controls_dba48d:
    ; backreference count 3, distance 32
    .byte $80, $1F
    ; literal count 44; subsequent asset bytes excluded
    .byte $2B
