.setcpu "65816"
.segment "CODE"
.org $7D00
map_control_0d7d00:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
