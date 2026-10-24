.setcpu "65816"
.segment "CODE"
.org $986A
map_control_0f986a:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
