; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $986D
boss_lz_controls_db986d:
    ; backreference count 3, distance 222
    .byte $80, $DD
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
