.setcpu "65816"
.segment "CODE"
.org $1363
map_control_0e1363:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
