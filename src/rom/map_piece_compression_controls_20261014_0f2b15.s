.setcpu "65816"
.segment "CODE"
.org $2B15
map_control_0f2b15:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
