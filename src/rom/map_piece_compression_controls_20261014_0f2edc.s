.setcpu "65816"
.segment "CODE"
.org $2EDC
map_control_0f2edc:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
