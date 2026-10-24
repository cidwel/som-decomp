.setcpu "65816"
.segment "CODE"
.org $DF13
map_control_0ddf13:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
