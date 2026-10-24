.setcpu "65816"
.segment "CODE"
.org $E4D0
map_control_0fe4d0:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
