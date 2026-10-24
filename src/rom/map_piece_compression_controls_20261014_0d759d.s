.setcpu "65816"
.segment "CODE"
.org $759D
map_control_0d759d:
    .byte $E0 ; previous-row copy escape
    .byte $4B ; row-distance/count
