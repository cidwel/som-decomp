.setcpu "65816"
.segment "CODE"
.org $1FCD
map_control_0e1fcd:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
