.setcpu "65816"
.segment "CODE"
.org $39BA
map_control_0c39ba:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
