.setcpu "65816"
.segment "CODE"
.org $FF34
map_control_0dff34:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
