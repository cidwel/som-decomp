.setcpu "65816"
.segment "CODE"
.org $6E71
map_control_0f6e71:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $8A ; distance low bit/count
