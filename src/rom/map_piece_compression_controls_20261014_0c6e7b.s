.setcpu "65816"
.segment "CODE"
.org $6E7B
map_control_0c6e7b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
