; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $022F
boss_lz_controls_db022f:
    ; backreference count 5, distance 216
    .byte $A0, $D7
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
