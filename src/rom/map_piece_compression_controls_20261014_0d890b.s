.setcpu "65816"
.segment "CODE"
.org $890B
map_control_0d890b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
