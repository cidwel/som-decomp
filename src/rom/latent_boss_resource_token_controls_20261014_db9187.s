; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9187
boss_lz_controls_db9187:
    ; backreference count 4, distance 64
    .byte $90, $3F
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
