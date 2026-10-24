.setcpu "65816"
.segment "CODE"
.org $67D6
map_control_0f67d6:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
