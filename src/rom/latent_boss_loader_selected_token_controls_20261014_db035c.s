; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $035C
boss_lz_controls_db035c:
    ; backreference count 4, distance 100
    .byte $90, $63
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
