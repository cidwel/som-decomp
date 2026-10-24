.setcpu "65816"
.segment "CODE"
.org $0E49
map_control_0d0e49:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
