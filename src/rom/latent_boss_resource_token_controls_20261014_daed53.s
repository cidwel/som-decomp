; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $ED53
boss_lz_controls_daed53:
    ; backreference count 4, distance 230
    .byte $90, $E5
    ; backreference count 3, distance 1954
    .byte $87, $A1
    ; literal count 13; subsequent asset bytes excluded
    .byte $0C
