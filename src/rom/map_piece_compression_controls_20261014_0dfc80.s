.setcpu "65816"
.segment "CODE"
.org $FC80
map_control_0dfc80:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
