; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $A2B4
boss_lz_controls_dba2b4:
    ; backreference count 3, distance 563
    .byte $82, $32
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
