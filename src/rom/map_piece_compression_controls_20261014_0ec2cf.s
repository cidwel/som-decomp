.setcpu "65816"
.segment "CODE"
.org $C2CF
map_control_0ec2cf:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
