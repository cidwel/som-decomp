.setcpu "65816"
.segment "CODE"
.org $C60C
map_control_0dc60c:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
