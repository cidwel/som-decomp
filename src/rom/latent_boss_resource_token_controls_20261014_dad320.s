; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D320
boss_lz_controls_dad320:
    ; backreference count 5, distance 1047
    .byte $94, $16
    ; literal count 20; subsequent asset bytes excluded
    .byte $13
