; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $B72C
boss_lz_controls_dbb72c:
    ; backreference count 4, distance 446
    .byte $85, $BD
    ; literal count 52; subsequent asset bytes excluded
    .byte $33
