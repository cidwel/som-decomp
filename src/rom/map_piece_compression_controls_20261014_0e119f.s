.setcpu "65816"
.segment "CODE"
.org $119F
map_control_0e119f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
