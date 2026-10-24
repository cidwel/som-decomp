.setcpu "65816"
.segment "CODE"
.org $D4EA
map_control_0dd4ea:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
