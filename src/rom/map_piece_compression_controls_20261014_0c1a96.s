.setcpu "65816"
.segment "CODE"
.org $1A96
map_control_0c1a96:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
