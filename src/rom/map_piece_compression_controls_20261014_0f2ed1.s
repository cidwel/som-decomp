.setcpu "65816"
.segment "CODE"
.org $2ED1
map_control_0f2ed1:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
