.setcpu "65816"
.segment "CODE"
.org $73FA
map_control_0c73fa:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
