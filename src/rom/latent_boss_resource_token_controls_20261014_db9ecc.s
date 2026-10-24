; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9ECC
boss_lz_controls_db9ecc:
    ; backreference count 15, distance 882
    .byte $E3, $71
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
