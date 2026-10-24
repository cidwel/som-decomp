.setcpu "65816"
.segment "CODE"
.org $1515
map_control_0c1515:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
