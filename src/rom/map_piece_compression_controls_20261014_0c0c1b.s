.setcpu "65816"
.segment "CODE"
.org $0C1B
map_control_0c0c1b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
