.setcpu "65816"
.segment "CODE"
.org $981E
map_control_0f981e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
