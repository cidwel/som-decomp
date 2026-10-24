.setcpu "65816"
.segment "CODE"
.org $FB7A
map_control_0cfb7a:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
