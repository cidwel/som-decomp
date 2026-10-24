.setcpu "65816"
.segment "CODE"
.org $909D
map_control_0f909d:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
