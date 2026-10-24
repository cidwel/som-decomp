.setcpu "65816"
.segment "CODE"
.org $E179
map_control_0de179:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
