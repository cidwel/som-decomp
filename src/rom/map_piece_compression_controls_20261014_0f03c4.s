.setcpu "65816"
.segment "CODE"
.org $03C4
map_control_0f03c4:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
