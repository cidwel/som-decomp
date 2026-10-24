.setcpu "65816"
.segment "CODE"
.org $AF67
map_control_0faf67:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
