.setcpu "65816"
.segment "CODE"
.org $6BB4
map_control_0d6bb4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
