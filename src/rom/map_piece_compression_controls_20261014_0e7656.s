.setcpu "65816"
.segment "CODE"
.org $7656
map_control_0e7656:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
