.setcpu "65816"
.segment "CODE"
.org $F700
map_control_0ef700:
    .byte $E0 ; previous-row copy escape
    .byte $B8 ; row-distance/count
