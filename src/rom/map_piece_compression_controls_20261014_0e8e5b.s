.setcpu "65816"
.segment "CODE"
.org $8E5B
map_control_0e8e5b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
