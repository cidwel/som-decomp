.setcpu "65816"
.segment "CODE"
.org $24D6
map_control_0f24d6:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
