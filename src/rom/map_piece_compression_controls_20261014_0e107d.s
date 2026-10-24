.setcpu "65816"
.segment "CODE"
.org $107D
map_control_0e107d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
