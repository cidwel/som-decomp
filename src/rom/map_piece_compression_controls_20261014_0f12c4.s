.setcpu "65816"
.segment "CODE"
.org $12C4
map_control_0f12c4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
