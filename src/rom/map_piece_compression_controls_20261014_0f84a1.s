.setcpu "65816"
.segment "CODE"
.org $84A1
map_control_0f84a1:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
