.setcpu "65816"
.segment "CODE"
.org $0013
map_control_0f0013:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
