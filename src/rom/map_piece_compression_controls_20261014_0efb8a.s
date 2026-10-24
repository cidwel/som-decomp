.setcpu "65816"
.segment "CODE"
.org $FB8A
map_control_0efb8a:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
