.setcpu "65816"
.segment "CODE"
.org $34CE
map_control_0f34ce:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
