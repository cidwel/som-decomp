.setcpu "65816"
.segment "CODE"
.org $FFF7
map_control_0efff7:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
