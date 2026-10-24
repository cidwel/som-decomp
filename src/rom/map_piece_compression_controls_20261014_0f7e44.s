.setcpu "65816"
.segment "CODE"
.org $7E44
map_control_0f7e44:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
