.setcpu "65816"
.segment "CODE"
.org $2D87
map_control_0f2d87:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
