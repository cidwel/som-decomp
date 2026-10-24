.setcpu "65816"
.segment "CODE"
.org $DE97
map_control_0ede97:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
