.setcpu "65816"
.segment "CODE"
.org $5FE1
map_control_0f5fe1:
    .byte $D6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
