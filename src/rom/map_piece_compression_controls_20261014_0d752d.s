.setcpu "65816"
.segment "CODE"
.org $752D
map_control_0d752d:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
    .byte $C4 ; same-value copy count/distance
