.setcpu "65816"
.segment "CODE"
.org $F62A
map_control_0ef62a:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
