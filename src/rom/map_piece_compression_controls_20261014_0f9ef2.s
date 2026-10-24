.setcpu "65816"
.segment "CODE"
.org $9EF2
map_control_0f9ef2:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
