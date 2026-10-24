.setcpu "65816"
.segment "CODE"
.org $5479
map_control_0e5479:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
