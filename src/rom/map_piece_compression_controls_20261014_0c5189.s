.setcpu "65816"
.segment "CODE"
.org $5189
map_control_0c5189:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
