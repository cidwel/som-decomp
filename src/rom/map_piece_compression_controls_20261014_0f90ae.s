.setcpu "65816"
.segment "CODE"
.org $90AE
map_control_0f90ae:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
