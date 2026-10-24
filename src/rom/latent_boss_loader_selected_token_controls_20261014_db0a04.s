; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A04
boss_lz_controls_db0a04:
    ; backreference count 3, distance 540
    .byte $82, $1B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
