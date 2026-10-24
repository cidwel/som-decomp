.setcpu "65816"
.segment "CODE"
.org $637C
map_control_0c637c:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
