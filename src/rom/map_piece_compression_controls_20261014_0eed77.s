.setcpu "65816"
.segment "CODE"
.org $ED77
map_control_0eed77:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
