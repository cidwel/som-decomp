.setcpu "65816"
.segment "CODE"
.org $57B8
map_control_0f57b8:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
