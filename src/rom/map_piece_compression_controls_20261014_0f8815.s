.setcpu "65816"
.segment "CODE"
.org $8815
map_control_0f8815:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
