.setcpu "65816"
.segment "CODE"
.org $2FD5
map_control_0d2fd5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
