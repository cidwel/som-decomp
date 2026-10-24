.setcpu "65816"
.segment "CODE"
.org $858A
map_control_0d858a:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
