.setcpu "65816"
.segment "CODE"
.org $79E4
map_control_0f79e4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
