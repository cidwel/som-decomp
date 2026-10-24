.setcpu "65816"
.segment "CODE"
.org $F725
map_control_0df725:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
