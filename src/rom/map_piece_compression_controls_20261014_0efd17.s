.setcpu "65816"
.segment "CODE"
.org $FD17
map_control_0efd17:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
