.setcpu "65816"
.segment "CODE"
.org $D441
map_control_0fd441:
    .byte $E8 ; backreference distance high bits
    .byte $43 ; distance low bit/count
