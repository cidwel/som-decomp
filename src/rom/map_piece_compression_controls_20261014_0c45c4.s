.setcpu "65816"
.segment "CODE"
.org $45C4
map_control_0c45c4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
