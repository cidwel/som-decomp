.setcpu "65816"
.segment "CODE"
.org $242A
map_control_0f242a:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
