.setcpu "65816"
.segment "CODE"
.org $6071
map_control_0d6071:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C3 ; same-value copy count/distance
