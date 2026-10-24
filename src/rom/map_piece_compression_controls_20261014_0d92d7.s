.setcpu "65816"
.segment "CODE"
.org $92D7
map_control_0d92d7:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
