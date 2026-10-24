; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $EFEE
boss_lz_controls_daefee:
    ; backreference count 3, distance 978
    .byte $83, $D1
    ; literal count 128; subsequent asset bytes excluded
    .byte $7F
