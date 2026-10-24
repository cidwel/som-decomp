; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $E8DC
boss_lz_controls_dae8dc:
    ; backreference count 4, distance 203
    .byte $90, $CA
    ; backreference count 3, distance 267
    .byte $81, $0A
    ; literal count 15; subsequent asset bytes excluded
    .byte $0E
