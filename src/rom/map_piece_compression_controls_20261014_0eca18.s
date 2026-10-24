.setcpu "65816"
.segment "CODE"
.org $CA18
map_control_0eca18:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
