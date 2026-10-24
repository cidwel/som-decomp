.setcpu "65816"
.segment "CODE"
.org $E750
map_control_0de750:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
