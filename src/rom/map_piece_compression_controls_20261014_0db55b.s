.setcpu "65816"
.segment "CODE"
.org $B55B
map_control_0db55b:
    .byte $E5 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
