.setcpu "65816"
.segment "CODE"
.org $8998
map_control_0c8998:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
