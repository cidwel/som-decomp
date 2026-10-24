.setcpu "65816"
.segment "CODE"
.org $67CF
map_control_0c67cf:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
