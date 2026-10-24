.setcpu "65816"
.segment "CODE"
.org $4B85
map_control_0c4b85:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
