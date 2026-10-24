; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $96DD
boss_lz_controls_db96dd:
    ; backreference count 3, distance 1189
    .byte $84, $A4
    ; literal count 32; subsequent asset bytes excluded
    .byte $1F
