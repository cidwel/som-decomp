.setcpu "65816"
.segment "CODE"
.org $BB8D
map_control_0dbb8d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
