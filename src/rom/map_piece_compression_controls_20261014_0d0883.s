.setcpu "65816"
.segment "CODE"
.org $0883
map_control_0d0883:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
