.setcpu "65816"
.segment "CODE"
.org $1CB2
map_control_0f1cb2:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
