.setcpu "65816"
.segment "CODE"
.org $4897
map_control_0f4897:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
