.setcpu "65816"
.segment "CODE"
.org $75E9
map_control_0f75e9:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
