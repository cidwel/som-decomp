.setcpu "65816"
.segment "CODE"
.org $64EA
map_control_0d64ea:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
