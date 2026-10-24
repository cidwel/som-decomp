.setcpu "65816"
.segment "CODE"
.org $C900
map_control_0ec900:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
