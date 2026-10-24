; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $93C9
boss_lz_controls_db93c9:
    ; backreference count 4, distance 65
    .byte $90, $40
    ; literal count 27; subsequent asset bytes excluded
    .byte $1A
