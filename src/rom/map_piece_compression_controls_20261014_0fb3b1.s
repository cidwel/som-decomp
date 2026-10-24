.setcpu "65816"
.segment "CODE"
.org $B3B1
map_control_0fb3b1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
