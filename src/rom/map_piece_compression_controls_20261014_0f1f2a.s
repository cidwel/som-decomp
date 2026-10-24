.setcpu "65816"
.segment "CODE"
.org $1F2A
map_control_0f1f2a:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
