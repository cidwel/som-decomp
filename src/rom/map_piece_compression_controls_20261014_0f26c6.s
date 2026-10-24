.setcpu "65816"
.segment "CODE"
.org $26C6
map_control_0f26c6:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
