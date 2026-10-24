.setcpu "65816"
.segment "CODE"
.org $0C15
map_control_0c0c15:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
