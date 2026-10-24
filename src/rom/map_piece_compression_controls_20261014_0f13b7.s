.setcpu "65816"
.segment "CODE"
.org $13B7
map_control_0f13b7:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
