.setcpu "65816"
.segment "CODE"
.org $C2A4
map_control_0ec2a4:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
