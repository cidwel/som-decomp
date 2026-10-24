.setcpu "65816"
.segment "CODE"
.org $110E
map_control_0c110e:
    .byte $E0 ; previous-row copy escape
    .byte $B5 ; row-distance/count
