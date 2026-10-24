.setcpu "65816"
.segment "CODE"
.org $703A
map_control_0c703a:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
