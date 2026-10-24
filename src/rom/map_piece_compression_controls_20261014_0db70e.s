.setcpu "65816"
.segment "CODE"
.org $B70E
map_control_0db70e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
