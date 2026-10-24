.setcpu "65816"
.segment "CODE"
.org $654B
map_control_0d654b:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
