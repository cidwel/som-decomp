.setcpu "65816"
.segment "CODE"
.org $2953
map_control_0c2953:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
