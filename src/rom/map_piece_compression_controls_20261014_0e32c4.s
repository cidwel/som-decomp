.setcpu "65816"
.segment "CODE"
.org $32C4
map_control_0e32c4:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
