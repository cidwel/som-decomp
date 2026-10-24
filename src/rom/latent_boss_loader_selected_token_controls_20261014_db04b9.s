; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $04B9
boss_lz_controls_db04b9:
    ; backreference count 5, distance 721
    .byte $A2, $D0
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
