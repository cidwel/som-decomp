; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $CD1B
boss_lz_controls_dbcd1b:
    ; backreference count 4, distance 1728
    .byte $96, $BF
    ; literal count 16; subsequent asset bytes excluded
    .byte $0F
