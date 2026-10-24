.setcpu "65816"
.segment "CODE"
.org $07D0
map_control_0f07d0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
