.setcpu "65816"
.segment "CODE"
.org $53FD
map_control_0d53fd:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
