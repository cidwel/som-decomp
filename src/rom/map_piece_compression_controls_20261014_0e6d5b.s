.setcpu "65816"
.segment "CODE"
.org $6D5B
map_control_0e6d5b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
