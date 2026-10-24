.setcpu "65816"
.segment "CODE"
.org $C33A
map_control_0ec33a:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
