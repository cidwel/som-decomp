.setcpu "65816"
.segment "CODE"
.org $BBE4
map_control_0dbbe4:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
