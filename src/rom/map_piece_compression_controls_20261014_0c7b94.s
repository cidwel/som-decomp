.setcpu "65816"
.segment "CODE"
.org $7B94
map_control_0c7b94:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
