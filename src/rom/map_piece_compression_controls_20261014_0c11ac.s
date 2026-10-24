.setcpu "65816"
.segment "CODE"
.org $11AC
map_control_0c11ac:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
