.setcpu "65816"
.segment "CODE"
.org $41F2
map_control_0f41f2:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
