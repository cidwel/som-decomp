.setcpu "65816"
.segment "CODE"
.org $1BE9
map_control_0d1be9:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
