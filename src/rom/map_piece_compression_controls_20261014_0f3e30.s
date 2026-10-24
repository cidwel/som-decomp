.setcpu "65816"
.segment "CODE"
.org $3E30
map_control_0f3e30:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
