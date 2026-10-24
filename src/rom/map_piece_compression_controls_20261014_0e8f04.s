.setcpu "65816"
.segment "CODE"
.org $8F04
map_control_0e8f04:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
