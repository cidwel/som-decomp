.setcpu "65816"
.segment "CODE"
.org $AD3A
map_control_0fad3a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
