.setcpu "65816"
.segment "CODE"
.org $4C36
map_control_0f4c36:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
