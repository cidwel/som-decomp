.setcpu "65816"
.segment "CODE"
.org $662F
map_control_0f662f:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
