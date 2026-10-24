.setcpu "65816"
.segment "CODE"
.org $0E34
map_control_0d0e34:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
