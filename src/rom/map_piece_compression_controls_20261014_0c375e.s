.setcpu "65816"
.segment "CODE"
.org $375E
map_control_0c375e:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
