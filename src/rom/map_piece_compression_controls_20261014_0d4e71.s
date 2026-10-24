.setcpu "65816"
.segment "CODE"
.org $4E71
map_control_0d4e71:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
