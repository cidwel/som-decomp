.setcpu "65816"
.segment "CODE"
.org $6FAE
map_control_0e6fae:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
