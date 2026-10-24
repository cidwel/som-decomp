.setcpu "65816"
.segment "CODE"
.org $7F10
map_control_0c7f10:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
