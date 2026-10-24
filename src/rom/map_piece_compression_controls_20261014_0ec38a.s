.setcpu "65816"
.segment "CODE"
.org $C38A
map_control_0ec38a:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
