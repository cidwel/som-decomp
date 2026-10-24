.setcpu "65816"
.segment "CODE"
.org $D5B4
map_control_0ed5b4:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
