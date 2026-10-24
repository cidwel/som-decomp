.setcpu "65816"
.segment "CODE"
.org $12B2
map_control_0f12b2:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
