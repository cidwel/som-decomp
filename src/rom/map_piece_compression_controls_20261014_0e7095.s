.setcpu "65816"
.segment "CODE"
.org $7095
map_control_0e7095:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $C3 ; same-value copy count/distance
