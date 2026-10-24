.setcpu "65816"
.segment "CODE"
.org $AC87
map_control_0dac87:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
