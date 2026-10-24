.setcpu "65816"
.segment "CODE"
.org $FF02
map_control_0dff02:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
