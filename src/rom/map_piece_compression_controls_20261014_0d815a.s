.setcpu "65816"
.segment "CODE"
.org $815A
map_control_0d815a:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
