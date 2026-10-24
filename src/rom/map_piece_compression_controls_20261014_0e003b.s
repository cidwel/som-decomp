.setcpu "65816"
.segment "CODE"
.org $003B
map_control_0e003b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
