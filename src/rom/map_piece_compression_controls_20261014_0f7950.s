.setcpu "65816"
.segment "CODE"
.org $7950
map_control_0f7950:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
