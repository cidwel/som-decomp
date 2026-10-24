.setcpu "65816"
.segment "CODE"
.org $E134
map_control_0de134:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
