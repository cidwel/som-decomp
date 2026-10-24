.setcpu "65816"
.segment "CODE"
.org $00D0
map_control_0f00d0:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
