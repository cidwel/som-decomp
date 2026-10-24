.setcpu "65816"
.segment "CODE"
.org $1C55
map_control_0f1c55:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
