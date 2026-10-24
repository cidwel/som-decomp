.setcpu "65816"
.segment "CODE"
.org $BED1
map_control_0ebed1:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
