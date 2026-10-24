.setcpu "65816"
.segment "CODE"
.org $AB0C
map_control_0eab0c:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
