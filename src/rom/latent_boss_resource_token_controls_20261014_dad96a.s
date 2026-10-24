; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D96A
boss_lz_controls_dad96a:
    ; backreference count 3, distance 68
    .byte $80, $43
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
