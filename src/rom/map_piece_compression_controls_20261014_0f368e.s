.setcpu "65816"
.segment "CODE"
.org $368E
map_control_0f368e:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
