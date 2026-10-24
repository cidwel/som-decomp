.setcpu "65816"
.segment "CODE"
.org $CA5A
map_control_0eca5a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C4 ; same-value copy count/distance
