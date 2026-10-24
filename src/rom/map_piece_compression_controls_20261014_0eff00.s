.setcpu "65816"
.segment "CODE"
.org $FF00
map_control_0eff00:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
