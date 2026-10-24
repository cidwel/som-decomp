.setcpu "65816"
.segment "CODE"
.org $D7E0
map_control_0ed7e0:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
