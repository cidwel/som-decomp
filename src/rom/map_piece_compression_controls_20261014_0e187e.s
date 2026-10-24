.setcpu "65816"
.segment "CODE"
.org $187E
map_control_0e187e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
