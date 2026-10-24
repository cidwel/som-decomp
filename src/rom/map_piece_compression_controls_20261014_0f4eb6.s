.setcpu "65816"
.segment "CODE"
.org $4EB6
map_control_0f4eb6:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
