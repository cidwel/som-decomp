.setcpu "65816"
.segment "CODE"
.org $78E1
map_control_0c78e1:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
