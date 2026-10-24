.setcpu "65816"
.segment "CODE"
.org $1BE5
map_control_0e1be5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
