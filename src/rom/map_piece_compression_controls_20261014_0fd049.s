.setcpu "65816"
.segment "CODE"
.org $D049
map_control_0fd049:
    .byte $E8 ; backreference distance high bits
    .byte $47 ; distance low bit/count
