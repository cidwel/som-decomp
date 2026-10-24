.setcpu "65816"
.segment "CODE"
.org $D5CC
map_control_0fd5cc:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
