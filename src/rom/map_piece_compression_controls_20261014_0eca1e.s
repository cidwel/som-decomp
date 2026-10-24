.setcpu "65816"
.segment "CODE"
.org $CA1E
map_control_0eca1e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C4 ; same-value copy count/distance
