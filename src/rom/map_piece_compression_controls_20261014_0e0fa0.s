.setcpu "65816"
.segment "CODE"
.org $0FA0
map_control_0e0fa0:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
