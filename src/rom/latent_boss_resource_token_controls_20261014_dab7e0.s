; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B7E0
boss_lz_controls_dab7e0:
    ; backreference count 3, distance 343
    .byte $81, $56
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
