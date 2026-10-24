.setcpu "65816"
.segment "CODE"
.org $3826
map_control_0f3826:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C4 ; same-value copy count/distance
