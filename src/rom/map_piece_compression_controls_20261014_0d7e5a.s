.setcpu "65816"
.segment "CODE"
.org $7E5A
map_control_0d7e5a:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
