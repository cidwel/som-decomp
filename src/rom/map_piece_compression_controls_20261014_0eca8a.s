.setcpu "65816"
.segment "CODE"
.org $CA8A
map_control_0eca8a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
