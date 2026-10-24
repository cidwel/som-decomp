.setcpu "65816"
.segment "CODE"
.org $EE13
map_control_0eee13:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
