.setcpu "65816"
.segment "CODE"
.org $CA8F
map_control_0eca8f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
