.setcpu "65816"
.segment "CODE"
.org $FE11
map_control_0dfe11:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
