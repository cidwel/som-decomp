.setcpu "65816"
.segment "CODE"
.org $6A52
map_control_0f6a52:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
