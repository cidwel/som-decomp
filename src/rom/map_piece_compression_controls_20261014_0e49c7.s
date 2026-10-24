.setcpu "65816"
.segment "CODE"
.org $49C7
map_control_0e49c7:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
