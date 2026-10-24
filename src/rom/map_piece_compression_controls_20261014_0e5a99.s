.setcpu "65816"
.segment "CODE"
.org $5A99
map_control_0e5a99:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
