.setcpu "65816"
.segment "CODE"
.org $00C3
map_control_0f00c3:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $C9 ; same-value copy count/distance
