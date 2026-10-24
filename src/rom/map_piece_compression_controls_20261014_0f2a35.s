.setcpu "65816"
.segment "CODE"
.org $2A35
map_control_0f2a35:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
