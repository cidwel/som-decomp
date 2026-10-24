.setcpu "65816"
.segment "CODE"
.org $CE1B
map_control_0ece1b:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
