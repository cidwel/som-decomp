.setcpu "65816"
.segment "CODE"
.org $D04C
map_control_0fd04c:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
