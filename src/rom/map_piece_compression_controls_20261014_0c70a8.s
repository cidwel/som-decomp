.setcpu "65816"
.segment "CODE"
.org $70A8
map_control_0c70a8:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
