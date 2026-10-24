; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0841
boss_lz_controls_db0841:
    ; backreference count 5, distance 2755
    .byte $AA, $C2
    ; backreference count 5, distance 1238
    .byte $A4, $D5
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
