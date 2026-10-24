.setcpu "65816"
.segment "CODE"
.org $F5E2
map_control_0df5e2:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
