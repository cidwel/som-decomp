.setcpu "65816"
.segment "CODE"
.org $351D
map_control_0c351d:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
