.setcpu "65816"
.segment "CODE"
.org $F291
map_control_0cf291:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
