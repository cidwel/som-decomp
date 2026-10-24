.setcpu "65816"
.segment "CODE"
.org $0C39
map_control_0c0c39:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
