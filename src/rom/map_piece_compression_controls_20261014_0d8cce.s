.setcpu "65816"
.segment "CODE"
.org $8CCE
map_control_0d8cce:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
