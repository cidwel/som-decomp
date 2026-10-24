.setcpu "65816"
.segment "CODE"
.org $8321
map_control_0d8321:
    .byte $E3 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
