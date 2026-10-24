.setcpu "65816"
.segment "CODE"
.org $310D
map_control_0f310d:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
