.setcpu "65816"
.segment "CODE"
.org $98D2
map_control_0f98d2:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
