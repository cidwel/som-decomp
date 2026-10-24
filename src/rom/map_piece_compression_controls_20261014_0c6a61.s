.setcpu "65816"
.segment "CODE"
.org $6A61
map_control_0c6a61:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
