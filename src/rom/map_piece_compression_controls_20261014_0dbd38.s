.setcpu "65816"
.segment "CODE"
.org $BD38
map_control_0dbd38:
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
