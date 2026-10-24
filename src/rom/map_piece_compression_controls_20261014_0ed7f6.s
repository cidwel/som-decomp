.setcpu "65816"
.segment "CODE"
.org $D7F6
map_control_0ed7f6:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
