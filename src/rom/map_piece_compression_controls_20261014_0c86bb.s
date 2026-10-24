.setcpu "65816"
.segment "CODE"
.org $86BB
map_control_0c86bb:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
