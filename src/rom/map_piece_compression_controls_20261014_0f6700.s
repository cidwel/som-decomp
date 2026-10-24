.setcpu "65816"
.segment "CODE"
.org $6700
map_control_0f6700:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
