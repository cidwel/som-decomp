.setcpu "65816"
.segment "CODE"
.org $9444
map_control_0e9444:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
