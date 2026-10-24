.setcpu "65816"
.segment "CODE"
.org $FF89
map_control_0dff89:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
