.setcpu "65816"
.segment "CODE"
.org $15EA
map_control_0f15ea:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
