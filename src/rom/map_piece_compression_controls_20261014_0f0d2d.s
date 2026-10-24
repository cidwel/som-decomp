.setcpu "65816"
.segment "CODE"
.org $0D2D
map_control_0f0d2d:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
