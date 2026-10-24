.setcpu "65816"
.segment "CODE"
.org $2F91
map_control_0d2f91:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
