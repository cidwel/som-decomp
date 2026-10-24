.setcpu "65816"
.segment "CODE"
.org $48BA
map_control_0f48ba:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
