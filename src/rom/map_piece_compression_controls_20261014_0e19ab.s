.setcpu "65816"
.segment "CODE"
.org $19AB
map_control_0e19ab:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
