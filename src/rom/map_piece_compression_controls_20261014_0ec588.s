.setcpu "65816"
.segment "CODE"
.org $C588
map_control_0ec588:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
