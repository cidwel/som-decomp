; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $D88A
boss_lz_controls_dad88a:
    ; backreference count 5, distance 64
    .byte $90, $3F
    ; literal count 18; subsequent asset bytes excluded
    .byte $11
