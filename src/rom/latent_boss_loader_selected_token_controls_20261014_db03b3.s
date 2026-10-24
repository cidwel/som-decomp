; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $03B3
boss_lz_controls_db03b3:
    ; backreference count 3, distance 941
    .byte $83, $AC
    ; backreference count 3, distance 578
    .byte $82, $41
    ; backreference count 5, distance 19
    .byte $A0, $12
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
