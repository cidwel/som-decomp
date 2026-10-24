.setcpu "65816"
.segment "CODE"
.org $7505
map_control_0d7505:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
