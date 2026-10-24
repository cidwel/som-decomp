.setcpu "65816"
.segment "CODE"
.org $9592
map_control_0f9592:
    .byte $E8 ; backreference distance high bits
    .byte $4B ; distance low bit/count
