.setcpu "65816"
.segment "CODE"
.org $E473
map_control_0de473:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
