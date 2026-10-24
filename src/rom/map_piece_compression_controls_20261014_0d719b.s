.setcpu "65816"
.segment "CODE"
.org $719B
map_control_0d719b:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
