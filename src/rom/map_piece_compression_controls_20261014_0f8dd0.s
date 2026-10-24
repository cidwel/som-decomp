.setcpu "65816"
.segment "CODE"
.org $8DD0
map_control_0f8dd0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
