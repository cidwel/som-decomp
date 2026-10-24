.setcpu "65816"
.segment "CODE"
.org $9C40
map_control_0f9c40:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
