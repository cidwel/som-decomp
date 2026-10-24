.setcpu "65816"
.segment "CODE"
.org $919D
map_control_0c919d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
