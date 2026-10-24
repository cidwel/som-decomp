.setcpu "65816"
.segment "CODE"
.org $59BA
map_control_0e59ba:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
