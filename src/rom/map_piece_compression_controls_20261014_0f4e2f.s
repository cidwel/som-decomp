.setcpu "65816"
.segment "CODE"
.org $4E2F
map_control_0f4e2f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
