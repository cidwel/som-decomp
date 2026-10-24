.setcpu "65816"
.segment "CODE"
.org $7B92
map_control_0d7b92:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
