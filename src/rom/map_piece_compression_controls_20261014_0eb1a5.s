.setcpu "65816"
.segment "CODE"
.org $B1A5
map_control_0eb1a5:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
