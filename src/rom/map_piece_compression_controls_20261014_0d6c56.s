.setcpu "65816"
.segment "CODE"
.org $6C56
map_control_0d6c56:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
