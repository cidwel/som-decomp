.setcpu "65816"
.segment "CODE"
.org $C7E1
map_control_0dc7e1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
