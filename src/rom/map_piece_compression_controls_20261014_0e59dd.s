.setcpu "65816"
.segment "CODE"
.org $59DD
map_control_0e59dd:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
