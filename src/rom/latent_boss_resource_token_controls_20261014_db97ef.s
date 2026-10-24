; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $97EF
boss_lz_controls_db97ef:
    ; backreference count 4, distance 11
    .byte $90, $0A
    ; backreference count 3, distance 2320
    .byte $89, $0F
    ; literal count 4; subsequent asset bytes excluded
    .byte $03
