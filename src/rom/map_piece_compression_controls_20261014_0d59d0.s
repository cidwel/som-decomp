.setcpu "65816"
.segment "CODE"
.org $59D0
map_control_0d59d0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
