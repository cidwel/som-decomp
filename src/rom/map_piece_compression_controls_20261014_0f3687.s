.setcpu "65816"
.segment "CODE"
.org $3687
map_control_0f3687:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
