; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $90FE
boss_lz_controls_db90fe:
    ; backreference count 5, distance 89
    .byte $A0, $58
    ; literal count 55; subsequent asset bytes excluded
    .byte $36
