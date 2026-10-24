.setcpu "65816"
.segment "CODE"
.org $7AD3
map_control_0f7ad3:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
