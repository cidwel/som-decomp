.setcpu "65816"
.segment "CODE"
.org $71EA
map_control_0c71ea:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
