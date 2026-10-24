; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $048E
boss_lz_controls_db048e:
    ; backreference count 3, distance 944
    .byte $83, $AF
    ; literal count 1; subsequent asset bytes excluded
    .byte $00
