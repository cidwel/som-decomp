.setcpu "65816"
.segment "CODE"
.org $4455
map_control_0f4455:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
