.setcpu "65816"
.segment "CODE"
.org $FDF2
map_control_0dfdf2:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
