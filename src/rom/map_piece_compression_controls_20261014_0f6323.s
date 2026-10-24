.setcpu "65816"
.segment "CODE"
.org $6323
map_control_0f6323:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
