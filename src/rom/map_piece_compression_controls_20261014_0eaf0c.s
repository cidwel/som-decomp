.setcpu "65816"
.segment "CODE"
.org $AF0C
map_control_0eaf0c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
