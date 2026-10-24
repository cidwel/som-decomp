; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03AF
boss_lz_controls_db03af:
    ; backreference count 7, distance 20
    .byte $C0, $13
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
