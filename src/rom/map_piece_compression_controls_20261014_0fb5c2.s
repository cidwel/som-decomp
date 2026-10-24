.setcpu "65816"
.segment "CODE"
.org $B5C2
map_control_0fb5c2:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
