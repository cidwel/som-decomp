.setcpu "65816"
.segment "CODE"
.org $A1C3
map_control_0da1c3:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
