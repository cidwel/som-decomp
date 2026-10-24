.setcpu "65816"
.segment "CODE"
.org $4292
map_control_0f4292:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
