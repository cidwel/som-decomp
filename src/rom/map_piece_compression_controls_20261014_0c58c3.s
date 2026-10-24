.setcpu "65816"
.segment "CODE"
.org $58C3
map_control_0c58c3:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
