; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $009A
boss_lz_controls_db009a:
    ; backreference count 3, distance 152
    .byte $80, $97
    ; backreference count 5, distance 161
    .byte $A0, $A0
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
