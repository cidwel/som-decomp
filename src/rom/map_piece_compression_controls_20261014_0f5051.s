.setcpu "65816"
.segment "CODE"
.org $5051
map_control_0f5051:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
