.setcpu "65816"
.segment "CODE"
.org $D7D6
map_control_0fd7d6:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
