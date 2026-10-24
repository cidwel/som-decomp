.setcpu "65816"
.segment "CODE"
.org $0F88
map_control_0f0f88:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
