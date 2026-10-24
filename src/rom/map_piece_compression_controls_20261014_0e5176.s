.setcpu "65816"
.segment "CODE"
.org $5176
map_control_0e5176:
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
