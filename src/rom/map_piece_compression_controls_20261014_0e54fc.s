.setcpu "65816"
.segment "CODE"
.org $54FC
map_control_0e54fc:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
