.setcpu "65816"
.segment "CODE"
.org $5AAE
map_control_0e5aae:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
