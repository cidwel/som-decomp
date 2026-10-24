.setcpu "65816"
.segment "CODE"
.org $9006
map_control_0c9006:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
