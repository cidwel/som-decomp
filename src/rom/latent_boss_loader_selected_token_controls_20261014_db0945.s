; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $0945
boss_lz_controls_db0945:
    ; backreference count 4, distance 1186
    .byte $94, $A1
    ; backreference count 4, distance 3535
    .byte $9D, $CE
    ; backreference count 3, distance 1263
    .byte $84, $EE
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
