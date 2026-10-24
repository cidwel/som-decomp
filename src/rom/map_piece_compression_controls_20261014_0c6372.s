.setcpu "65816"
.segment "CODE"
.org $6372
map_control_0c6372:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
