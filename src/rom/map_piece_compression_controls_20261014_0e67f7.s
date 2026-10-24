.setcpu "65816"
.segment "CODE"
.org $67F7
map_control_0e67f7:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
