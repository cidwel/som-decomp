.setcpu "65816"
.segment "CODE"
.org $F394
map_control_0df394:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
