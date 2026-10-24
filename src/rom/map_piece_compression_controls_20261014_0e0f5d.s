.setcpu "65816"
.segment "CODE"
.org $0F5D
map_control_0e0f5d:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
