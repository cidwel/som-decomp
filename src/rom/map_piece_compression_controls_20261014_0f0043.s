.setcpu "65816"
.segment "CODE"
.org $0043
map_control_0f0043:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
