.setcpu "65816"
.segment "CODE"
.org $3598
map_control_0e3598:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
