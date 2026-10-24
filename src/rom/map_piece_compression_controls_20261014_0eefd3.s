.setcpu "65816"
.segment "CODE"
.org $EFD3
map_control_0eefd3:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
