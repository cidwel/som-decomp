; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ECB6
boss_lz_controls_daecb6:
    ; backreference count 5, distance 73
    .byte $A0, $48
    ; literal count 34; subsequent asset bytes excluded
    .byte $21
