; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D03B
boss_lz_controls_dbd03b:
    ; backreference count 4, distance 5
    .byte $90, $04
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
