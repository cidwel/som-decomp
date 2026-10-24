; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CAEB
boss_lz_controls_dacaeb:
    ; backreference count 5, distance 270
    .byte $91, $0D
    ; literal count 29; subsequent asset bytes excluded
    .byte $1C
