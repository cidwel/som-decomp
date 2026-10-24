.setcpu "65816"
.segment "CODE"
.org $0113
map_control_0f0113:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
