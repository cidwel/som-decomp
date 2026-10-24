.setcpu "65816"
.segment "CODE"
.org $FF44
map_control_0dff44:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
