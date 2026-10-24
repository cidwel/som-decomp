.setcpu "65816"
.segment "CODE"
.org $0846
map_control_0d0846:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
