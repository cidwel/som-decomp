.setcpu "65816"
.segment "CODE"
.org $13DE
map_control_0e13de:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
