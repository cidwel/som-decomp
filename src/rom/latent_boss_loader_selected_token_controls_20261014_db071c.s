; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $071C
boss_lz_controls_db071c:
    ; backreference count 6, distance 1160
    .byte $B4, $87
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
