.setcpu "65816"
.segment "CODE"
.org $85EF
map_control_0d85ef:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
