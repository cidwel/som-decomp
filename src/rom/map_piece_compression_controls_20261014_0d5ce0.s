.setcpu "65816"
.segment "CODE"
.org $5CE0
map_control_0d5ce0:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $D5 ; same-value copy count/distance
