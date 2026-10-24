.setcpu "65816"
.segment "CODE"
.org $B3B5
map_control_0fb3b5:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
