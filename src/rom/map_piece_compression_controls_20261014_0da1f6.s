.setcpu "65816"
.segment "CODE"
.org $A1F6
map_control_0da1f6:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
