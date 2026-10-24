.setcpu "65816"
.segment "CODE"
.org $C2E4
map_control_0ec2e4:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $6F ; distance low bit/count
