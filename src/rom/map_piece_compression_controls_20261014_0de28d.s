.setcpu "65816"
.segment "CODE"
.org $E28D
map_control_0de28d:
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
