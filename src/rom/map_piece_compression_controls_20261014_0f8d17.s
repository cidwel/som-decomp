.setcpu "65816"
.segment "CODE"
.org $8D17
map_control_0f8d17:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
