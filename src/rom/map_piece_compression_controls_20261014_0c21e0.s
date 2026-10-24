.setcpu "65816"
.segment "CODE"
.org $21E0
map_control_0c21e0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
