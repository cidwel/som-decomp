; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BB92
boss_lz_controls_dabb92:
    ; backreference count 3, distance 9
    .byte $80, $08
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
