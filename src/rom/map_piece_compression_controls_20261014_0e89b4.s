.setcpu "65816"
.segment "CODE"
.org $89B4
map_control_0e89b4:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
