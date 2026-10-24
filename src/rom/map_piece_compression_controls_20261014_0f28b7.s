.setcpu "65816"
.segment "CODE"
.org $28B7
map_control_0f28b7:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
