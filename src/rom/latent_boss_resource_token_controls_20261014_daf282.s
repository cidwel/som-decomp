; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $F282
boss_lz_controls_daf282:
    ; backreference count 3, distance 777
    .byte $83, $08
    ; literal count 12; subsequent asset bytes excluded
    .byte $0B
