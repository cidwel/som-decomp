.setcpu "65816"
.segment "CODE"
.org $7EF4
map_control_0d7ef4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C7 ; same-value copy count/distance
