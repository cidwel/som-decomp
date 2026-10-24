.setcpu "65816"
.segment "CODE"
.org $C702
map_control_0ec702:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
