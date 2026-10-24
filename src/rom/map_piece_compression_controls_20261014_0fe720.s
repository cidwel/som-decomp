.setcpu "65816"
.segment "CODE"
.org $E720
map_control_0fe720:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
