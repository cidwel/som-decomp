.setcpu "65816"
.segment "CODE"
.org $7AC7
map_control_0d7ac7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
