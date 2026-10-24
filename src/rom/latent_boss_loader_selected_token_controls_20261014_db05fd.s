; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $05FD
boss_lz_controls_db05fd:
    ; backreference count 3, distance 421
    .byte $81, $A4
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
