.setcpu "65816"
.segment "CODE"
.org $5CD6
map_control_0d5cd6:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
