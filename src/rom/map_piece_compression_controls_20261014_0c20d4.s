.setcpu "65816"
.segment "CODE"
.org $20D4
map_control_0c20d4:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
