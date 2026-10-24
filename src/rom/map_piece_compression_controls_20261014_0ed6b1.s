.setcpu "65816"
.segment "CODE"
.org $D6B1
map_control_0ed6b1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
