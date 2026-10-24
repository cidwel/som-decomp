; Numeric LZ control fields; literal graphics payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $9EC2
boss_lz_controls_db9ec2:
    ; backreference count 3, distance 244
    .byte $80, $F3
    ; literal count 2; subsequent asset bytes excluded
    .byte $01
