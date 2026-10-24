; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B618
boss_lz_controls_dbb618:
    ; backreference count 4, distance 137
    .byte $84, $88
    ; literal count 7; subsequent asset bytes excluded
    .byte $06
