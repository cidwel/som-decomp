.setcpu "65816"
.segment "CODE"
.org $E4E3
map_control_0fe4e3:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
