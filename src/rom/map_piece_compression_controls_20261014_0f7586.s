.setcpu "65816"
.segment "CODE"
.org $7586
map_control_0f7586:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
