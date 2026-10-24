.setcpu "65816"
.segment "CODE"
.org $78F2
map_control_0c78f2:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
