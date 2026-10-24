.setcpu "65816"
.segment "CODE"
.org $4A00
map_control_0f4a00:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
