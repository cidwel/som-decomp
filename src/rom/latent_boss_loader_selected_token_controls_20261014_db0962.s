; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0962
boss_lz_controls_db0962:
    ; backreference count 5, distance 480
    .byte $A1, $DF
    ; backreference count 5, distance 543
    .byte $A2, $1E
    ; backreference count 4, distance 1920
    .byte $97, $7F
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
