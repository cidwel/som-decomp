.setcpu "65816"
.segment "CODE"
.org $6ECA
map_control_0d6eca:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
