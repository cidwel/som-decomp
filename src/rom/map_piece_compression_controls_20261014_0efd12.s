.setcpu "65816"
.segment "CODE"
.org $FD12
map_control_0efd12:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
