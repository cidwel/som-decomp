.setcpu "65816"
.segment "CODE"
.org $5DDC
map_control_0e5ddc:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
