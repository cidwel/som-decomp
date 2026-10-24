.setcpu "65816"
.segment "CODE"
.org $0F60
map_control_0f0f60:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
