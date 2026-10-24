.setcpu "65816"
.segment "CODE"
.org $5E23
map_control_0d5e23:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
