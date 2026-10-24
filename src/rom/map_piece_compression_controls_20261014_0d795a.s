.setcpu "65816"
.segment "CODE"
.org $795A
map_control_0d795a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
