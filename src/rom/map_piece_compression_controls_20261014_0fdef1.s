.setcpu "65816"
.segment "CODE"
.org $DEF1
map_control_0fdef1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
