.setcpu "65816"
.segment "CODE"
.org $9EC2
map_control_0d9ec2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
