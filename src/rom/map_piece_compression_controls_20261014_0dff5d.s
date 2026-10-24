.setcpu "65816"
.segment "CODE"
.org $FF5D
map_control_0dff5d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
