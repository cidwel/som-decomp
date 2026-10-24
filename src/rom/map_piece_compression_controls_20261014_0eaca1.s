.setcpu "65816"
.segment "CODE"
.org $ACA1
map_control_0eaca1:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
