.setcpu "65816"
.segment "CODE"
.org $0415
map_control_0e0415:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
