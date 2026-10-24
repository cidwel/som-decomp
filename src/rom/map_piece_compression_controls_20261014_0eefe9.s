.setcpu "65816"
.segment "CODE"
.org $EFE9
map_control_0eefe9:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
