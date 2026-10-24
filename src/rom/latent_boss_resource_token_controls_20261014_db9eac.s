; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9EAC
boss_lz_controls_db9eac:
    ; backreference count 5, distance 213
    .byte $90, $D4
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
