; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0875
boss_lz_controls_db0875:
    ; backreference count 4, distance 51
    .byte $90, $32
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
