.setcpu "65816"
.segment "CODE"
.org $317F
map_control_0f317f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
