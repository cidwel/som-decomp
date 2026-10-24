.setcpu "65816"
.segment "CODE"
.org $9F8B
map_control_0d9f8b:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
