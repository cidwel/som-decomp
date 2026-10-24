.setcpu "65816"
.segment "CODE"
.org $12D5
map_control_0f12d5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
