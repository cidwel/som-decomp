.setcpu "65816"
.segment "CODE"
.org $99F9
map_control_0f99f9:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
