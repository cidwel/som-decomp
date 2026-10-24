.setcpu "65816"
.segment "CODE"
.org $D06A
map_control_0ed06a:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
