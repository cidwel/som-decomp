.setcpu "65816"
.segment "CODE"
.org $6435
map_control_0f6435:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
