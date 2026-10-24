.setcpu "65816"
.segment "CODE"
.org $FE2A
map_control_0dfe2a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
