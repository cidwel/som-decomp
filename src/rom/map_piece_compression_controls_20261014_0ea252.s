.setcpu "65816"
.segment "CODE"
.org $A252
map_control_0ea252:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
