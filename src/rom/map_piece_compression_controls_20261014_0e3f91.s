.setcpu "65816"
.segment "CODE"
.org $3F91
map_control_0e3f91:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
