.setcpu "65816"
.segment "CODE"
.org $407B
map_control_0c407b:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
