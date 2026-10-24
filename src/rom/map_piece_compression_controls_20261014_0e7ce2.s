.setcpu "65816"
.segment "CODE"
.org $7CE2
map_control_0e7ce2:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
