.setcpu "65816"
.segment "CODE"
.org $EC51
map_control_0eec51:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
