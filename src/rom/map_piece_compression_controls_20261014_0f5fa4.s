.setcpu "65816"
.segment "CODE"
.org $5FA4
map_control_0f5fa4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
