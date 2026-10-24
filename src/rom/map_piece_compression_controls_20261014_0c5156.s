.setcpu "65816"
.segment "CODE"
.org $5156
map_control_0c5156:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
