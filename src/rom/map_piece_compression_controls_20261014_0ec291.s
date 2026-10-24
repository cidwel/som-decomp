.setcpu "65816"
.segment "CODE"
.org $C291
map_control_0ec291:
    .byte $E0 ; previous-row copy escape
    .byte $C9 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
