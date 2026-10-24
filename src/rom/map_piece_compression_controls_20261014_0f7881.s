.setcpu "65816"
.segment "CODE"
.org $7881
map_control_0f7881:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
