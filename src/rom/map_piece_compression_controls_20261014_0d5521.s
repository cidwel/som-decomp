.setcpu "65816"
.segment "CODE"
.org $5521
map_control_0d5521:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
