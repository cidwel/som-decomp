; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $026E
boss_lz_controls_db026e:
    ; backreference count 5, distance 17
    .byte $A0, $10
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
