; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0A10
boss_lz_controls_db0a10:
    ; backreference count 3, distance 142
    .byte $80, $8D
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
