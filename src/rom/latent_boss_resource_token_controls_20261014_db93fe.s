; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $93FE
boss_lz_controls_db93fe:
    ; backreference count 4, distance 33
    .byte $90, $20
    ; literal count 24; subsequent asset bytes excluded
    .byte $17
