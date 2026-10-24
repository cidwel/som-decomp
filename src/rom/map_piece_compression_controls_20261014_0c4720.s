.setcpu "65816"
.segment "CODE"
.org $4720
map_control_0c4720:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
