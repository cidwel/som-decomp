.setcpu "65816"
.segment "CODE"
.org $50F7
map_control_0c50f7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
