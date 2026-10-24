.setcpu "65816"
.segment "CODE"
.org $B8B3
map_control_0db8b3:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
