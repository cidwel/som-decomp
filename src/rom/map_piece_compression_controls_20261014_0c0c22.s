.setcpu "65816"
.segment "CODE"
.org $0C22
map_control_0c0c22:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
