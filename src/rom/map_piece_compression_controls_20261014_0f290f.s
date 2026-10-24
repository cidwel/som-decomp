.setcpu "65816"
.segment "CODE"
.org $290F
map_control_0f290f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
