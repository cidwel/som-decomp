.setcpu "65816"
.segment "CODE"
.org $E4F7
map_control_0fe4f7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
