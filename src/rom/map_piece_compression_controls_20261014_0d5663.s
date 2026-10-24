.setcpu "65816"
.segment "CODE"
.org $5663
map_control_0d5663:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
