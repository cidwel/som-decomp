.setcpu "65816"
.segment "CODE"
.org $55C3
map_control_0f55c3:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
