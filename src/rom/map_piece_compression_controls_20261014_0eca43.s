.setcpu "65816"
.segment "CODE"
.org $CA43
map_control_0eca43:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
