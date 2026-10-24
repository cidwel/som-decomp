.setcpu "65816"
.segment "CODE"
.org $6E53
map_control_0c6e53:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
