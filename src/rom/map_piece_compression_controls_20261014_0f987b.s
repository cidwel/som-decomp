.setcpu "65816"
.segment "CODE"
.org $987B
map_control_0f987b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
