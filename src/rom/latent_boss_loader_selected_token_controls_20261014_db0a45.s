; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A45
boss_lz_controls_db0a45:
    ; backreference count 10, distance 2826
    .byte $FB, $09
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
