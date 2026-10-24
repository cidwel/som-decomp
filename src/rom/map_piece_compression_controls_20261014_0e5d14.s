.setcpu "65816"
.segment "CODE"
.org $5D14
map_control_0e5d14:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
