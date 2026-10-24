.setcpu "65816"
.segment "CODE"
.org $9092
map_control_0c9092:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $C7 ; same-value copy count/distance
