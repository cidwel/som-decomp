.setcpu "65816"
.segment "CODE"
.org $1BBD
map_control_0c1bbd:
    .byte $D4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
