; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A094
boss_lz_controls_dba094:
    ; backreference count 3, distance 331
    .byte $81, $4A
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
