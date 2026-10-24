.setcpu "65816"
.segment "CODE"
.org $92E5
map_control_0f92e5:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
