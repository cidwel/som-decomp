.setcpu "65816"
.segment "CODE"
.org $99B4
map_control_0f99b4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
