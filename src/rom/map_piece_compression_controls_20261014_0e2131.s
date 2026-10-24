.setcpu "65816"
.segment "CODE"
.org $2131
map_control_0e2131:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
