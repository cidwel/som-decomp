.setcpu "65816"
.segment "CODE"
.org $AF71
map_control_0faf71:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C9 ; same-value copy count/distance
