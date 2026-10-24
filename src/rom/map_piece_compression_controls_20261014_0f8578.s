.setcpu "65816"
.segment "CODE"
.org $8578
map_control_0f8578:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
