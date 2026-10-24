.setcpu "65816"
.segment "CODE"
.org $C7E8
map_control_0dc7e8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
