.setcpu "65816"
.segment "CODE"
.org $0E0A
map_control_0d0e0a:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
