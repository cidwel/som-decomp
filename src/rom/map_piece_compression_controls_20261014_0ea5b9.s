.setcpu "65816"
.segment "CODE"
.org $A5B9
map_control_0ea5b9:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
