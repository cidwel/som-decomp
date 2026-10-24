; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0981
boss_lz_controls_db0981:
    ; backreference count 5, distance 2748
    .byte $AA, $BB
    ; backreference count 5, distance 140
    .byte $A0, $8B
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
