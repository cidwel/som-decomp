.setcpu "65816"
.segment "CODE"
.org $0B78
map_control_0e0b78:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
