.setcpu "65816"
.segment "CODE"
.org $B068
map_control_0db068:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
