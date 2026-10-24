.setcpu "65816"
.segment "CODE"
.org $862D
map_control_0d862d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
