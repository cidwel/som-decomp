; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $00DD
boss_lz_controls_db00dd:
    ; backreference count 5, distance 48
    .byte $A0, $2F
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
