.setcpu "65816"
.segment "CODE"
.org $72D7
map_control_0d72d7:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
