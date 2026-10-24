.setcpu "65816"
.segment "CODE"
.org $2977
map_control_0f2977:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
