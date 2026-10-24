.setcpu "65816"
.segment "CODE"
.org $1C31
map_control_0e1c31:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
