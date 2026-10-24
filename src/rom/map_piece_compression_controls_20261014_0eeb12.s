.setcpu "65816"
.segment "CODE"
.org $EB12
map_control_0eeb12:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
