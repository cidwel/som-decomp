.setcpu "65816"
.segment "CODE"
.org $7138
map_control_0c7138:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
