; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $AD2B
boss_lz_controls_dbad2b:
    ; backreference count 4, distance 505
    .byte $85, $F8
    ; literal count 81; subsequent asset bytes excluded
    .byte $50
