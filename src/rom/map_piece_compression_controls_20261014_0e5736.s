.setcpu "65816"
.segment "CODE"
.org $5736
map_control_0e5736:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
