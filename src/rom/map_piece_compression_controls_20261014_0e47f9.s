.setcpu "65816"
.segment "CODE"
.org $47F9
map_control_0e47f9:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
