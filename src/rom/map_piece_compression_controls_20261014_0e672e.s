.setcpu "65816"
.segment "CODE"
.org $672E
map_control_0e672e:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
