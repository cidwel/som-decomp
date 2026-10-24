.setcpu "65816"
.segment "CODE"
.org $6150
map_control_0d6150:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
