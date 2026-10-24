.setcpu "65816"
.segment "CODE"
.org $47DF
map_control_0e47df:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
