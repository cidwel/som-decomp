.setcpu "65816"
.segment "CODE"
.org $8457
map_control_0e8457:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
