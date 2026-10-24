.setcpu "65816"
.segment "CODE"
.org $CB2D
map_control_0ecb2d:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
