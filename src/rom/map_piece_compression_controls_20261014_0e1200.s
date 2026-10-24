.setcpu "65816"
.segment "CODE"
.org $1200
map_control_0e1200:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
