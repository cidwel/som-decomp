.setcpu "65816"
.segment "CODE"
.org $4409
map_control_0f4409:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
