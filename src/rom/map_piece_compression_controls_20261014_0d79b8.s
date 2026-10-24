.setcpu "65816"
.segment "CODE"
.org $79B8
map_control_0d79b8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C5 ; same-value copy count/distance
