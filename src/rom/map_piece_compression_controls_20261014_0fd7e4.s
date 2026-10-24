.setcpu "65816"
.segment "CODE"
.org $D7E4
map_control_0fd7e4:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
