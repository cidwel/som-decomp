.setcpu "65816"
.segment "CODE"
.org $3B1B
map_control_0f3b1b:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
