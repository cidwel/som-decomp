.setcpu "65816"
.segment "CODE"
.org $1930
map_control_0e1930:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
