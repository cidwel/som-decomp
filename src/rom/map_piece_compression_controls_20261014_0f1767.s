.setcpu "65816"
.segment "CODE"
.org $1767
map_control_0f1767:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C3 ; same-value copy count/distance
