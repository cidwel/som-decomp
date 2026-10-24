.setcpu "65816"
.segment "CODE"
.org $3480
map_control_0f3480:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
