.setcpu "65816"
.segment "CODE"
.org $97A8
map_control_0e97a8:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
