.setcpu "65816"
.segment "CODE"
.org $F354
map_control_0df354:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
