; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0BF1
boss_lz_controls_db0bf1:
    ; backreference count 55, distance 1
    .byte $E8, $00
    ; backreference count 64, distance 512
    .byte $FB, $FF
    ; literal count 97; subsequent asset bytes excluded
    .byte $60
