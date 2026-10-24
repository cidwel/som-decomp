.setcpu "65816"
.segment "CODE"
.org $7B90
map_control_0c7b90:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
