.setcpu "65816"
.segment "CODE"
.org $0E5B
map_control_0d0e5b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
