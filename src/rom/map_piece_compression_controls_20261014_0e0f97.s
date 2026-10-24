.setcpu "65816"
.segment "CODE"
.org $0F97
map_control_0e0f97:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
