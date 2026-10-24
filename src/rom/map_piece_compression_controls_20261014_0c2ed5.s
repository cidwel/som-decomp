.setcpu "65816"
.segment "CODE"
.org $2ED5
map_control_0c2ed5:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
