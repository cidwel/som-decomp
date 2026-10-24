.setcpu "65816"
.segment "CODE"
.org $AF05
map_control_0faf05:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
