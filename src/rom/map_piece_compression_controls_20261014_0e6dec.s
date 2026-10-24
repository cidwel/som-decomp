.setcpu "65816"
.segment "CODE"
.org $6DEC
map_control_0e6dec:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
