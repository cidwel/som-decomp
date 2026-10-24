.setcpu "65816"
.segment "CODE"
.org $4E0B
map_control_0f4e0b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
