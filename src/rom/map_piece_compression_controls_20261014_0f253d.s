.setcpu "65816"
.segment "CODE"
.org $253D
map_control_0f253d:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
