.setcpu "65816"
.segment "CODE"
.org $BE8B
map_control_0dbe8b:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
