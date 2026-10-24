.setcpu "65816"
.segment "CODE"
.org $7AA3
map_control_0d7aa3:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
