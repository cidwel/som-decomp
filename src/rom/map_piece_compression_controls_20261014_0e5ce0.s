.setcpu "65816"
.segment "CODE"
.org $5CE0
map_control_0e5ce0:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
