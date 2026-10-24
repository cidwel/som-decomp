.setcpu "65816"
.segment "CODE"
.org $316D
map_control_0e316d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
