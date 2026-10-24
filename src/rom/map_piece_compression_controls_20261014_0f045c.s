.setcpu "65816"
.segment "CODE"
.org $045C
map_control_0f045c:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
