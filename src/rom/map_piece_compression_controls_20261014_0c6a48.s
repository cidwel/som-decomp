.setcpu "65816"
.segment "CODE"
.org $6A48
map_control_0c6a48:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
