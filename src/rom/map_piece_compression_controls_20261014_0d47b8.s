.setcpu "65816"
.segment "CODE"
.org $47B8
map_control_0d47b8:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
