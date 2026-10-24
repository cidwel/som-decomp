.setcpu "65816"
.segment "CODE"
.org $C15C
map_control_0dc15c:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
