.setcpu "65816"
.segment "CODE"
.org $4442
map_control_0e4442:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
