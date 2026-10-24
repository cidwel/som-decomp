; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B0F7
boss_lz_controls_dbb0f7:
    ; backreference count 11, distance 256
    .byte $A0, $FF
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
