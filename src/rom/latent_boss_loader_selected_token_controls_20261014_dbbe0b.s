; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BE0B
boss_lz_controls_dbbe0b:
    ; backreference count 3, distance 373
    .byte $81, $74
    ; literal count 30; subsequent asset bytes excluded
    .byte $1D
