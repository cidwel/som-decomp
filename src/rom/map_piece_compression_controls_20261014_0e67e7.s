.setcpu "65816"
.segment "CODE"
.org $67E7
map_control_0e67e7:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
