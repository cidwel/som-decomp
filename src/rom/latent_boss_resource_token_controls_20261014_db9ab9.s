; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9AB9
boss_lz_controls_db9ab9:
    ; backreference count 3, distance 49
    .byte $80, $30
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
