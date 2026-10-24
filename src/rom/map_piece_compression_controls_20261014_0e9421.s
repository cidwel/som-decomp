.setcpu "65816"
.segment "CODE"
.org $9421
map_control_0e9421:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $C4 ; same-value copy count/distance
