.setcpu "65816"
.segment "CODE"
.org $0E81
map_control_0d0e81:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
