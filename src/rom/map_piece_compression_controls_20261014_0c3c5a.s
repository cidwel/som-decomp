.setcpu "65816"
.segment "CODE"
.org $3C5A
map_control_0c3c5a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
