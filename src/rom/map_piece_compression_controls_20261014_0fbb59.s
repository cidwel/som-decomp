.setcpu "65816"
.segment "CODE"
.org $BB59
map_control_0fbb59:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
