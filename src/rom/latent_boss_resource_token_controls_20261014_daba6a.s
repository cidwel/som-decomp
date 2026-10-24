; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BA6A
boss_lz_controls_daba6a:
    ; backreference count 11, distance 114
    .byte $A0, $71
    ; literal count 6; subsequent asset bytes excluded
    .byte $05
