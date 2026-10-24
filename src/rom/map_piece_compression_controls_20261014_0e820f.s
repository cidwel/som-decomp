.setcpu "65816"
.segment "CODE"
.org $820F
map_control_0e820f:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
