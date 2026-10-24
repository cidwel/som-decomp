.setcpu "65816"
.segment "CODE"
.org $79C9
map_control_0d79c9:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D4 ; same-value copy count/distance
