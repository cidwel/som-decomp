; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D2F7
boss_lz_controls_dad2f7:
    ; backreference count 3, distance 27
    .byte $80, $1A
    ; literal count 11; subsequent asset bytes excluded
    .byte $0A
