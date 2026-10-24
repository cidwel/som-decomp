; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $BDFB
boss_lz_controls_dabdfb:
    ; backreference count 3, distance 160
    .byte $80, $9F
    ; literal count 5; subsequent asset bytes excluded
    .byte $04
