.setcpu "65816"
.segment "CODE"
.org $5073
map_control_0d5073:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
