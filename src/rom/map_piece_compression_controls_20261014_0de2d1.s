.setcpu "65816"
.segment "CODE"
.org $E2D1
map_control_0de2d1:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
