; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $93B5
boss_lz_controls_db93b5:
    ; backreference count 4, distance 65
    .byte $90, $40
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
