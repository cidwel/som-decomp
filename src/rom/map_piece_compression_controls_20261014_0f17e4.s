.setcpu "65816"
.segment "CODE"
.org $17E4
map_control_0f17e4:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
