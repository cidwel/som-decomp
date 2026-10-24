; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CB38
boss_lz_controls_dacb38:
    ; backreference count 18, distance 514
    .byte $FA, $01
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
