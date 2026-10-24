.setcpu "65816"
.segment "CODE"
.org $726A
map_control_0d726a:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
