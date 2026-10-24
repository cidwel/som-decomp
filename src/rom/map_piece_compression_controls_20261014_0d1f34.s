.setcpu "65816"
.segment "CODE"
.org $1F34
map_control_0d1f34:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
