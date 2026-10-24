.setcpu "65816"
.segment "CODE"
.org $4D28
map_control_0f4d28:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
