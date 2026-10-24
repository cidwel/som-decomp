.setcpu "65816"
.segment "CODE"
.org $3E5D
map_control_0e3e5d:
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
