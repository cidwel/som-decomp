; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B2A8
boss_lz_controls_dbb2a8:
    ; backreference count 3, distance 425
    .byte $81, $A8
    ; literal count 31; subsequent asset bytes excluded
    .byte $1E
