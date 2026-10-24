.setcpu "65816"
.segment "CODE"
.org $C2F6
map_control_0dc2f6:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
